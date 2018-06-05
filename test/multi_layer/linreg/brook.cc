#include "brook.h"

using Brook::Graph;

Graph::Graph()
: brook_variable (2, 2)
, brook_variable_1 (12, 2)
{
    brook_variable(0, 0) = 1.66342;
    brook_variable(0, 1) = 2.66782;
    brook_variable(1, 0) = 2.91753;
    brook_variable(1, 1) = 3.88729;
    brook_variable_1(0, 0) = 0.323334;
    brook_variable_1(0, 1) = 1.27705;
    brook_variable_1(1, 0) = -0.374818;
    brook_variable_1(1, 1) = 0.559612;
    brook_variable_1(2, 0) = 1.46122;
    brook_variable_1(2, 1) = 2.83092;
    brook_variable_1(3, 0) = 1.66102;
    brook_variable_1(3, 1) = 3.06128;
    brook_variable_1(4, 0) = 0.766809;
    brook_variable_1(4, 1) = 2.28129;
    brook_variable_1(5, 0) = -1.38781;
    brook_variable_1(5, 1) = 1.11605;
    brook_variable_1(6, 0) = -2.31379;
    brook_variable_1(6, 1) = 0.417051;
    brook_variable_1(7, 0) = 3.00981;
    brook_variable_1(7, 1) = 3.99277;
    brook_variable_1(8, 0) = 2.18128;
    brook_variable_1(8, 1) = 2.28184;
    brook_variable_1(9, 0) = -4.03633;
    brook_variable_1(9, 1) = -1.62922;
    brook_variable_1(10, 0) = -0.828486;
    brook_variable_1(10, 1) = 1.31531;
    brook_variable_1(11, 0) = 2.11137;
    brook_variable_1(11, 1) = 3.5224;
    
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

    Eigen::MatrixXd brook_matmul = brook_inputx * brook_variable;
    Eigen::MatrixXd brook_outputx = add(brook_matmul, brook_variable_1);
    return brook_outputx;
    
}
