import os
from shutil import copyfile

from jinja2 import Environment, FileSystemLoader, select_autoescape

from IR import IRNode, IROp


class CodeGenerator:
    def __init__(self, IR):
        self.IR = IR

    def _get_const_decl_code(self):
        code = []
        for c in self.IR.get_const_nodes():
            if not c.is_scalar:
                code.append('Eigen::MatrixXd %s;' % c.get_variable_name())
        return code

    def _get_constructor_init_list(self):
        code = []
        for c in self.IR.get_const_nodes():
            if not c.is_scalar:
                assert len(c.shape) == 2, 'Constant op with invalid shape: ' + str(c.shape)
                code.append('%s (%s, %s)' % (c.get_variable_name(), c.shape[0], c.shape[1]))
        return code

    def _get_constructor_body(self):
        # TODO: Handle if ndims == 1
        code = []
        for c in self.IR.get_const_nodes():
            if not c.is_scalar:
                for i in range(c.shape[0]):
                    for j in range(c.shape[1]):
                        code.append('%s(%s, %s) = %s;' % (c.get_variable_name(), i, j, c.resolved_value[i][j]))
        return code

    def _get_infer_param_list(self):
        code = ''
        for i in self.IR.get_input_nodes():
            code += 'Eigen::MatrixXd ' + i.get_variable_name() + ', '
        return code[:-2]

    def _get_infer_body(self):
        """
        Generates the code to be injected in the library template files.

        :return: List of code lines generated for the IRGraph
        :rtype: list[str]
        """
        last_node = self.IR.get_output_nodes()[0]  # TODO Support multiple output nodes
        code = self._get_infer_body_r(last_node)
        code.append('return ' + last_node.get_variable_name() + ';')
        return code

    def _get_infer_body_r(self, current_node):
        """
        Recursive function for code generation

        :param current_node: The current IRNode being inspected
        :type current_node: IRNode
        :return: List of code lines generated for the IR sub-graph ending at the current node
        :rtype: list[str]
        """

        if not current_node.is_visited:
            current_node.is_visited = True

            code_lines = []

            # Add code from predecessors
            predecessors = []
            for p in current_node.predecessors:
                p_node = self.IR.get_node(p)
                predecessors.append(p_node)
                code = self._get_infer_body_r(p_node)
                if (code is not None) and (len(code) > 0):
                    code_lines.extend(code)

            # Add code for current node
            type_ = current_node.get_type()

            if isinstance(current_node, IROp):
                if type_ == 'Add':
                    if len(predecessors) == 2:
                        if (predecessors[0].op.type == 'Const') and predecessors[0].is_scalar:
                            code = 'Eigen::MatrixXd %s = %s.array() + %f;' % (
                                current_node.get_variable_name(),
                                predecessors[1].get_variable_name(),
                                predecessors[0].get_resolved_value()
                            )
                        elif (predecessors[1].op.type == 'Const') and predecessors[1].is_scalar:
                            code = 'Eigen::MatrixXd %s = %s.array() + %f;' % (
                                current_node.get_variable_name(),
                                predecessors[0].get_variable_name(),
                                predecessors[1].get_resolved_value()
                            )
                        else:
                            code = 'Eigen::MatrixXd %s = add(%s, %s);' % (
                                current_node.get_variable_name(),
                                predecessors[0].get_variable_name(),
                                predecessors[1].get_variable_name()
                            )
                    else:
                        raise ValueError('Only binary addition operator is currently supported.')

                elif type_ == 'Sub':
                    if len(predecessors) == 2:
                        if (predecessors[0].op.type == 'Const') and predecessors[0].is_scalar:
                            code = 'Eigen::MatrixXd %s = %f - %s.array();' % (
                                current_node.get_variable_name(),
                                predecessors[0].get_resolved_value(),
                                predecessors[1].get_variable_name()
                            )
                        elif (predecessors[1].op.type == 'Const') and predecessors[1].is_scalar:
                            code = 'Eigen::MatrixXd %s = %s.array() - %f;' % (
                                current_node.get_variable_name(),
                                predecessors[0].get_variable_name(),
                                predecessors[1].get_resolved_value()
                            )
                        else:
                            code = 'Eigen::MatrixXd %s = sub(%s, %s);' % (
                                current_node.get_variable_name(),
                                predecessors[0].get_variable_name(),
                                predecessors[1].get_variable_name()
                            )
                    else:
                        raise ValueError('Only binary subtraction operator is currently supported.')

                elif type_ == 'Mul':
                    if len(predecessors) == 2:
                        if (predecessors[0].op.type == 'Const') and predecessors[0].is_scalar:
                            code = 'Eigen::MatrixXd %s = %f * %s;' % (
                                current_node.get_variable_name(),
                                predecessors[0].get_resolved_value(),
                                predecessors[1].get_variable_name()
                            )
                        elif (predecessors[1].op.type == 'Const') and predecessors[1].is_scalar:
                            code = 'Eigen::MatrixXd %s = %s * %f;' % (
                                current_node.get_variable_name(),
                                predecessors[0].get_variable_name(),
                                predecessors[1].get_resolved_value()
                            )
                        else:
                            code = 'Eigen::MatrixXd %s = mul(%s, %s);' % (
                                current_node.get_variable_name(),
                                predecessors[0].get_variable_name(),
                                predecessors[1].get_variable_name()
                            )
                    else:
                        raise ValueError('Only binary multiplication operator is currently supported.')

                elif type_ == 'RealDiv':
                    if len(predecessors) == 2:
                        if (predecessors[0].op.type == 'Const') and predecessors[0].is_scalar:
                            code = 'Eigen::MatrixXd %s = %f / %s.array();' % (
                                current_node.get_variable_name(),
                                predecessors[0].get_resolved_value(),
                                predecessors[1].get_variable_name()
                            )
                        elif (predecessors[1].op.type == 'Const') and predecessors[1].is_scalar:
                            code = 'Eigen::MatrixXd %s = %s.array() / %f;' % (
                                current_node.get_variable_name(),
                                predecessors[0].get_variable_name(),
                                predecessors[1].get_resolved_value()
                            )
                        else:
                            code = 'Eigen::MatrixXd %s = div(%s, %s);' % (
                                current_node.get_variable_name(),
                                predecessors[0].get_variable_name(),
                                predecessors[1].get_variable_name()
                            )
                    else:
                        raise ValueError('Only binary multiplication operator is currently supported.')

                elif type_ == 'MatMul':
                    if len(predecessors) == 2:
                        code = 'Eigen::MatrixXd %s = %s * %s;' % (
                            current_node.get_variable_name(),
                            predecessors[0].get_variable_name(),
                            predecessors[1].get_variable_name()
                        )
                    else:
                        raise ValueError('Only binary matrix multiplication operator is currently supported.')

                elif type_ == 'Relu':
                    if len(predecessors) == 1:
                        code = 'Eigen::MatrixXd %s = %s.cwiseMax(0);' % (
                            current_node.get_variable_name(),
                            predecessors[0].get_variable_name()
                        )
                    else:
                        raise ValueError('Only unary ReLU operator is currently supported.')

                elif type_ == 'Relu6':
                    if len(predecessors) == 1:
                        code = 'Eigen::MatrixXd %s = %s.cwiseMax(0).cwiseMin(6);' % (
                            current_node.get_variable_name(),
                            predecessors[0].get_variable_name()
                        )
                    else:
                        raise ValueError('Only unary ReLU6 operator is currently supported.')

                elif type_ == 'Maximum':
                    if len(predecessors) == 2:
                        if (predecessors[0].op.type == 'Const') and predecessors[0].is_scalar:
                            code = 'Eigen::MatrixXd %s = %s.cwiseMax(%f);' % (
                                current_node.get_variable_name(),
                                predecessors[1].get_variable_name(),
                                predecessors[0].get_resolved_value()
                            )
                        elif (predecessors[1].op.type == 'Const') and predecessors[1].is_scalar:
                            code = 'Eigen::MatrixXd %s = %s.cwiseMax(%f);' % (
                                current_node.get_variable_name(),
                                predecessors[0].get_variable_name(),
                                predecessors[1].get_resolved_value()
                            )
                        else:
                            code = 'Eigen::MatrixXd %s = %s.cwiseMax(%s);' % (
                                current_node.get_variable_name(),
                                predecessors[0].get_variable_name(),
                                predecessors[1].get_variable_name()
                            )
                    else:
                        raise ValueError('Only binary Maximum operator is currently supported.')

                else:
                    raise NotImplementedError('Unknown operation: <' + type_ + '>. Aborting code generation.')

            elif isinstance(current_node, IRNode):
                if type_ == 'Placeholder' or type_ == 'Const' or type_ == 'Identity':
                    return code_lines
                else:
                    raise NotImplementedError('Unknown node type: <' + type_ + '>. Aborting code generation.')
            else:
                raise ValueError('Graph introspection failure. Aborting code generation.')

            code_lines.append(code)
            return code_lines

    def _get_flags(self):
        return self.IR.flags

    def generate_template(self, lib_cc_filename, lib_h_filename, templates, out_dirs):
        """

        It generates the C++ files based on Jinja templates and the IR obtained earlier.

        :param lib_cc_filename: The file name for the implementation file that this will generate.
        :param lib_h_filename: The file name for the header file that this will generate.
        :param templates: The paths of the template files for the header and implementation files.
        :param out_dirs: The paths of the directories where the files should be placed / generated.
        :return: None
        """

        template_dir = os.path.dirname(os.path.abspath(templates[0]))  # TODO do something smarter here
        template_loader = FileSystemLoader(searchpath=template_dir)

        # Initialize environment
        env = Environment(
            loader=template_loader,
            autoescape=select_autoescape(['c++'])
        )

        # Import templates
        template_header = env.get_template(lib_h_filename + '.template')
        template_cc = env.get_template(lib_cc_filename + '.template')

        # Create sub directories
        out_dir_init = out_dirs[0]
        if not os.path.exists(out_dir_init):
            os.makedirs(out_dir_init)

        # Render header file
        f_header = open(out_dir_init + '/' + lib_h_filename, 'w')
        f_cc = open(out_dir_init + '/' + lib_cc_filename, 'w')

        # Prepare parameter list for the infer() function
        infer_param_list_str = self._get_infer_param_list()
        field_decl_list = self._get_const_decl_code()
        flags = self._get_flags()

        field_init_code = self._get_constructor_init_list()
        constructor_body = self._get_constructor_body()
        infer_body = self._get_infer_body()

        print >> f_header, template_header.render(
            infer_param_list_str=infer_param_list_str,
            field_decl_list=field_decl_list,
            flags=flags
        )
        print >> f_cc, template_cc.render(
            field_init_code=field_init_code,
            init_code=constructor_body,
            param_list_str=infer_param_list_str,
            infer_code=infer_body,
            flags=flags
        )

        f_header.close()
        f_cc.close()

        print "Generated files:"
        print os.path.abspath(f_header.name)
        print os.path.abspath(f_cc.name)

        for other_dir in out_dirs[1:]:

            # Create sub directories
            if not os.path.exists(other_dir):
                os.makedirs(other_dir)

            new_f_header_path = os.path.join(other_dir, lib_h_filename)
            new_f_cc_path = os.path.join(other_dir, lib_cc_filename)
            copyfile(f_header.name, new_f_header_path)
            copyfile(f_cc.name, new_f_cc_path)

            print os.path.abspath(new_f_header_path)
            print os.path.abspath(new_f_cc_path)
