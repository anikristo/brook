#include "brook.h"

using Brook::Graph;

Graph::Graph()
: brook_elemwisefactor (2, 1)
{
    brook_elemwisefactor(0, 0) = 1.0;
    brook_elemwisefactor(1, 0) = 2.0;
    
}

Eigen::MatrixXd Graph::convertToEigenMatrix(std::vector<std::vector<double> > data) {
    Eigen::MatrixXd mat(data.size(), data[0].size());
    for (uint i = 0; i < data.size(); i++){
        mat.row(i) = Eigen::VectorXd::Map(&data[i][0], data[i].size());
    }

    return mat;
}

Eigen::MatrixXd mul(Eigen::MatrixXd a, Eigen::MatrixXd b) {

    if ((a.rows() == b.rows()) and (a.cols() == b.cols())) // No need for broadcasting
        return a.cwiseProduct(b);

    // Full broadcast from a
    else if ((a.rows() == 1) and (a.cols() == 1) )
        return b.array() * a(0, 0);

    // Full broadcast from b
    else if ((b.rows() == 1) and (b.cols() == 1) )
        return a.array() * b(0, 0);

    // Row-wise broadcast from a
    else if ((a.rows() == 1) && (a.cols() == b.cols())) {
        Eigen::Map<Eigen::RowVectorXd> *a_vector = new Eigen::Map<Eigen::RowVectorXd>(a.data(), a.cols());
        return b.array().rowwise() * a_vector->array();

    // Row-wise broadcast from b
    } else if ((b.rows() == 1) && (a.cols() == b.cols())) {
        Eigen::Map<Eigen::RowVectorXd>  *b_vector = new Eigen::Map<Eigen::RowVectorXd>(b.data(), b.cols());
        return a.array().rowwise() * b_vector->array();

    // Column-wise broadcast from a
    } else if ((a.cols() == 1) && (a.rows() == b.rows())) {
         Eigen::Map<Eigen::VectorXd>  *a_vector = new Eigen::Map<Eigen::VectorXd>(a.data(), a.rows());
         return b.array().colwise() * a_vector->array();

    // Column-wise broadcast from b
    } else if ((b.cols() == 1) && (a.rows() == b.rows())) {
             Eigen::Map<Eigen::VectorXd>  *b_vector = new Eigen::Map<Eigen::VectorXd>(b.data(), b.rows());
             return a.array().colwise() * b_vector->array();

    } else { // Must never come here normally
        throw "Abnormal matrix dimensions for addition. Exiting...";
    }
}
Eigen::MatrixXd Graph::infer(Eigen::MatrixXd brook_inputx){

    Eigen::MatrixXd brook_outputx = mul(brook_inputx, brook_elemwisefactor);
    return brook_outputx;
    
}
