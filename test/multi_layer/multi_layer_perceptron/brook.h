#ifndef BROOK_LIB_H
#define BROOK_LIB_H

#include "third_party/eigen3/Eigen/Dense"
#include <vector>
#include <iostream>

namespace Brook {
    class Graph;
}

class Brook::Graph {
public:

    // Default constructor
    Graph();

    // Class methods
    Eigen::MatrixXd infer(Eigen::MatrixXd brook_inputx);
    static Eigen::MatrixXd convertToEigenMatrix(std::vector<std::vector<double> >);

private:

    // Member fields
    Eigen::MatrixXd brook_variable;
    Eigen::MatrixXd brook_variable_1;
    Eigen::MatrixXd brook_variable_2;
    Eigen::MatrixXd brook_variable_3;
    Eigen::MatrixXd brook_variable_4;
    Eigen::MatrixXd brook_variable_5;
    Eigen::MatrixXd brook_variable_6;
    Eigen::MatrixXd brook_variable_7;
    

};

#endif //BROOK_LIB_H
