import argparse
import os

import tensorflow as tf

from CodeGenerator import CodeGenerator
from IR import IRGraph

# CONSTANTS
LIB_CC_FILE_NAME = 'brook.cc'
LIB_H_FILE_NAME = 'brook.h'
GRAPH_OP_PREFIX = 'brook'


def _load_graph(frozen_graph_filename):
    """
    Inflates the binary protobuf file into a TF session
    :param frozen_graph_filename: The file name of the frozen model
    :return: A TF graph object belonging to the .pb file
    """
    with tf.gfile.GFile(frozen_graph_filename, "rb") as f:
        graph_def = tf.GraphDef()
        graph_def.ParseFromString(f.read())

    with tf.Graph().as_default() as graph:
        tf.import_graph_def(
            graph_def,
            input_map=None,
            return_elements=None,
            name=GRAPH_OP_PREFIX,
            op_dict=None,
            producer_op_list=None
        )
    return graph


# Execution starts here
os.environ['TF_CPP_MIN_LOG_LEVEL'] = '2'
if __name__ == '__main__':
    # Parse arguments
    parser = argparse.ArgumentParser(
        description="For all given frozen models, creates C++ library files in each given output folder")
    parser.add_argument("-f", "--frozen-model-filenames", nargs='+', help="Frozen model files to import")
    parser.add_argument("-i", "--input-node-names", nargs='+', help="Names of the input nodes")
    parser.add_argument("-o", "--output-node-names", nargs='+', help="Names of the output nodes")
    parser.add_argument("-t", "--templates", nargs='+', help="List of paths for the Jinja2 templates")
    parser.add_argument("-d", "--output-directories", nargs='+',
                        help="Paths of the output directories for the generated files")
    args = parser.parse_args()

    for model_file in args.frozen_model_filenames:
        # Create a Graph object from the default
        graph = _load_graph(model_file)

        # Cut the graph to only include the nodes between the declared input and the output nodes
        ir = IRGraph(graph, args.input_node_names, args.output_node_names, prefix=GRAPH_OP_PREFIX)

        generator = CodeGenerator(ir)
        generator.generate_template(LIB_CC_FILE_NAME, LIB_H_FILE_NAME, args.templates, args.output_directories)

    print "Code generated for %s in %s" % (args.frozen_model_filenames, args.output_directories)
