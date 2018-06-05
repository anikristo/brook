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
    

};

#endif //BROOK_LIB_H
