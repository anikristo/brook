import os

import tensorflow as tf
from tensorflow.python.framework import graph_util


def freeze_graph(chkp_dir, out_dir, graph_name, output_node_names):
    """
    Freezes the tf.Variable nodes in the graph and converts them to tf.Constant. This generates a PB file in the folder.

    :param chkp_dir: The path to the directory containing the checkpoint files

    :param out_dir: The path to the output directory for the frozen model file (.pb file)

    :param graph_name: The name of the graph as persisted in the checkpoint file. This will be used for the
    frozen model as well.

    :param output_node_names: A list of strings with the names of the output nodes (The subgraph will be cut until here)
    The nodes beyond this will be dumped.

    :return: None
    """

    # Meta graph's file path
    input_checkpoint = tf.train.get_checkpoint_state(chkp_dir).model_checkpoint_path

    # Frozen graph's full file path
    out_graph_filename = os.path.join(out_dir, graph_name + '.pb')

    # We import the meta graph and retrieve a Saver
    # We clear devices to allow TensorFlow to control on which device it will load operations
    saver = tf.train.import_meta_graph(input_checkpoint + '.meta', clear_devices=True)

    # We retrieve the protobuf graph definition
    input_graph_def = tf.get_default_graph().as_graph_def()

    # We start a session and restore the graph weights
    with tf.Session() as sess:
        saver.restore(sess, input_checkpoint)

        # We use a built-in TF helper to export variables to constants
        output_graph_def = graph_util.convert_variables_to_constants(
            sess,  # The session is used to retrieve the weights
            input_graph_def,  # The graph_def is used to retrieve the nodes
            output_node_names  # The output node names are used to select the useful nodes
        )

        # Finally we serialize and dump the output graph to the filesystem
        with tf.gfile.GFile(out_graph_filename, 'wb') as f:
            f.write(output_graph_def.SerializeToString())


def read_test_results(in_dir, file_name):
    """
    TODO: Read testcase inputs from file with same format as down

    """

    inputs = []
    with open(os.path.join(in_dir, file_name), 'r') as f:
        for line in f:
            # Initially we will get the input dimensions
            dimensions = line.split()

            input_matrix = []
            for row_idx in range(int(dimensions[0])):
                row = map(lambda x: float(x), next(f).split())
                input_matrix.append(row)

            inputs.append(input_matrix)

    return inputs


def write_test_results(result_list, out_dir, file_name):
    """
    Generates a text file that contains the results of inferring the TF model with the given TEST inputs.

    The format of the file is as follows:

    For every test result in result_list:
    `
        <DIM_1> <DIM_2>
        <results[0]>    -> Each line (row) has length <DIM_2> (columns)
        <results[1]>
        <results[2]>
        ...             -> There are <DIM_1> lines (rows)
    `

    :param result_list: A list of results received by inferring the TF model
    :type result_list: list
    :param out_dir: The directory where to place the output file
    :type out_dir: str
    :param file_name: The name of the file that will contain the results
    :type file_name: str
    :return:
    """
    with open(os.path.join(out_dir, file_name), 'w') as f:
        for res in result_list:
            dim_1 = res.shape[0]
            dim_2 = res.shape[1]
            f.write(str(dim_1) + " " + str(dim_2) + "\n")
            for row in res:
                f.write(' '.join(str(col) for col in row) + '\n')
