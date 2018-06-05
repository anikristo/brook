import argparse
import os
import sys

import tensorflow as tf

sys.path.append(os.path.join(os.path.dirname(__file__), '../../..'))
from util import freeze_graph, read_test_results, write_test_results

os.environ['TF_CPP_MIN_LOG_LEVEL'] = '3'
# Execution starts here
if __name__ == '__main__':

    # Parse arguments
    parser = argparse.ArgumentParser()
    parser.add_argument("-g", "--graph-name", default='graph',
                        help="Name of the binary Protobuf file that will contain the frozen graph")
    parser.add_argument("-o", "--out-dir-name",
                        help="Name of the output directory where the test results will be saved")
    parser.add_argument("-c", "--chkp-dir-name",
                        help="Name of the output directory where the checkpoint files will be saved")
    parser.add_argument("-i", "--in-dir-name", help="Name of the int directory where the test cases will be read from")
    args = parser.parse_args()

    # Read arguments
    GRAPH_NAME = args.graph_name
    OUT_DIR_NAME = args.out_dir_name
    IN_DIR_NAME = args.in_dir_name
    PB_DIR_NAME = args.chkp_dir_name
    CHKP_DIR_NAME = os.path.join(args.chkp_dir_name, 'chkp')

    # Multiplies by [[0, 2]]
    x_train = [
        [1, 0],
        [2, 0],
        [0, 3],
        [0, 4],
        [5, 3],
        [1, 3],
        [7, 4],
        [5, 6],
        [0, 0]
    ]

    y_train = [
        [0],
        [0],
        [6],
        [8],
        [6],
        [6],
        [8],
        [12],
        [0]
    ]

    # Model input and output
    x = tf.placeholder(shape=[None, 2], dtype=tf.float32, name='inputx')
    mulFactor = tf.Variable(tf.random_normal([2, 1]), name='mulFactor')
    model = tf.matmul(x, mulFactor, name='outputx')
    y = tf.placeholder(dtype=tf.float32, shape=(None, 1))

    # loss
    loss = tf.reduce_sum(tf.square(model - y) / 18, name='loss')  # sum of the squares

    # optimizer
    optimizer = tf.train.GradientDescentOptimizer(0.01)
    train = optimizer.minimize(loss)

    # training loop
    sess = tf.Session()
    sess.run(tf.global_variables_initializer())
    for i in range(1000):
        sess.run(train, {x: x_train, y: y_train})

    # Create dirs as necessary
    if not os.path.exists(CHKP_DIR_NAME):
        os.makedirs(CHKP_DIR_NAME)

    # Save model's checkpoint files
    tf.train.Saver().save(sess, os.path.join(CHKP_DIR_NAME, GRAPH_NAME + '.chkp'))
    tf.summary.FileWriter(CHKP_DIR_NAME, sess.graph)

    # Freeze graph
    freeze_graph(chkp_dir=CHKP_DIR_NAME, out_dir=PB_DIR_NAME, graph_name=GRAPH_NAME, output_node_names=['outputx'])

    # Output results for tests
    test_inputs = read_test_results(in_dir=IN_DIR_NAME, file_name="tf.in")
    test_results = []
    for test_input in test_inputs:
        test_results.append(sess.run(model, feed_dict={
            x: test_input
        }))
    write_test_results(result_list=test_results, out_dir=OUT_DIR_NAME, file_name="tf.out")

