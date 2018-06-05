#include "brook.h"

using Brook::Graph;

Graph::Graph()
: brook_elemwiseadd (1, 9)
{
    brook_elemwiseadd(0, 0) = 0.301785;
    brook_elemwiseadd(0, 1) = 2.13193;
    brook_elemwiseadd(0, 2) = 1.94813;
    brook_elemwiseadd(0, 3) = 2.77421;
    brook_elemwiseadd(0, 4) = 3.36709;
    brook_elemwiseadd(0, 5) = 4.16784;
    brook_elemwiseadd(0, 6) = 4.70501;
    brook_elemwiseadd(0, 7) = 5.87816;
    brook_elemwiseadd(0, 8) = 6.76246;
    
}

Eigen::MatrixXd Graph::convertToEigenMatrix(std::vector<std::vector<double> > data) {
    Eigen::MatrixXd mat(data.size(), data[0].size());
    for (uint i = 0; i < data.size(); i++){
        mat.row(i) = Eigen::VectorXd::Map(&data[i][0], data[i].size());
    }

    return mat;
}

Eigen::MatrixXd add(Eigen::MatrixXd a, Eigen::MatrixXd b) {

    if ((a.rows() == b.rows()) and (a.cols() == b.cols())) // No need for broadcasting
        return a + b;

    // Full broadcast from a
    else if ((a.rows() == 1) and (a.cols() == 1) )
        return b.array() + a(0, 0);

    // Full broadcast from b
    else if ((b.rows() == 1) and (b.cols() == 1) )
        return a.array() + b(0, 0);

    // Row-wise broadcast from a
    else if ((a.rows() == 1) && (a.cols() == b.cols())) {
        Eigen::Map<Eigen::RowVectorXd> *a_vector = new Eigen::Map<Eigen::RowVectorXd>(a.data(), a.cols());
        return b.rowwise() + *a_vector;

    // Row-wise broadcast from b
    } else if ((b.rows() == 1) && (a.cols() == b.cols())) {
        Eigen::Map<Eigen::RowVectorXd>  *b_vector = new Eigen::Map<Eigen::RowVectorXd>(b.data(), b.cols());
        return a.rowwise() + *b_vector;

    // Column-wise broadcast from a
    } else if ((a.cols() == 1) && (a.rows() == b.rows())) {
         Eigen::Map<Eigen::VectorXd>  *a_vector = new Eigen::Map<Eigen::VectorXd>(a.data(), a.rows());
         return b.colwise() + *a_vector;

    // Column-wise broadcast from b
    } else if ((b.cols() == 1) && (a.rows() == b.rows())) {
         Eigen::Map<Eigen::VectorXd>  *b_vector = new Eigen::Map<Eigen::VectorXd>(b.data(), b.rows());
         return a.colwise() + *b_vector;

    } else { // Must never come here normally
        throw "Abnormal matrix dimensions for addition. Exiting...";
    }
}
Eigen::MatrixXd Graph::infer(Eigen::MatrixXd brook_inputx){

    Eigen::MatrixXd brook_outputx = add(brook_inputx, brook_elemwiseadd);
    return brook_outputx;
    
}
