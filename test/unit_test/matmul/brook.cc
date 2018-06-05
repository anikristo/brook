#include "brook.h"

using Brook::Graph;

Graph::Graph()
: brook_mulfactor (2, 1)
{
    brook_mulfactor(0, 0) = 9.525e-07;
    brook_mulfactor(1, 0) = 2.0;
    
}

Eigen::MatrixXd Graph::convertToEigenMatrix(std::vector<std::vector<double> > data) {
    Eigen::MatrixXd mat(data.size(), data[0].size());
    for (uint i = 0; i < data.size(); i++){
        mat.row(i) = Eigen::VectorXd::Map(&data[i][0], data[i].size());
    }

    return mat;
}

Eigen::MatrixXd Graph::infer(Eigen::MatrixXd brook_inputx){

    Eigen::MatrixXd brook_outputx = brook_inputx * brook_mulfactor;
    return brook_outputx;
    
}
