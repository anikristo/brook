#include "gtest/gtest.h"
#include "brook.h"

#include "test/utils.h"

using namespace Brook;

TEST(MultiplyColBroadcast, Infer){

    // Read input for test files
    std::string tf_in_file = "test/unit_test/multiply_col_broadcast/tf.in";
    std::string tf_out_file = "test/unit_test/multiply_col_broadcast/tf.out";

    std::vector<Eigen::MatrixXd> tf_in = read_file(tf_in_file);
    std::vector<Eigen::MatrixXd> tf_out = read_file(tf_out_file);

    bool accu = true;
    int nr_tests = tf_in.size();

    if(nr_tests == tf_out.size()){
        Graph g;
        for(auto idx = 0; idx < nr_tests; ++idx){
            Eigen::MatrixXd y_pred = g.infer(tf_in[idx]);
            Eigen::MatrixXd y_true = tf_out[idx];

            accu &= y_true.isApprox(y_pred, 1e-5);
        }

        EXPECT_TRUE(accu);

    } else {
        std::cerr << "The number of test case inputs and results must be equal." << std::endl;
        exit(-1);
    }
}

int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);
  ::testing::GTEST_FLAG(filter) = "MultiplyColBroadcast.*";
  return RUN_ALL_TESTS();
}