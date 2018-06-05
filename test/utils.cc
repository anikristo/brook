#include "utils.h"

using namespace std;

vector<Eigen::MatrixXd> read_file(string filename){

    vector<Eigen::MatrixXd> x;

    ifstream input_file(filename);

    // Check if exists and open the file
    if (input_file.good()){

        string line;
        while(getline(input_file, line)){
            stringstream line_stream(line);

            int dimensions[2];
            double value;

            line_stream >> value;
            dimensions[0] = int(value);

            line_stream >> value;
            dimensions[1] = int(value);

            Eigen::MatrixXd matrix;
            matrix.setZero(dimensions[0], dimensions[1]);
            for( auto row_idx = 0; row_idx < dimensions[0]; row_idx++){

                getline(input_file, line);
                stringstream row_stream(line);

                for( auto col_idx = 0; col_idx < dimensions[1]; col_idx++){
                    row_stream >> value;
                    matrix(row_idx, col_idx) = value;
                }
            }
            x.push_back(matrix);
        }

        input_file.close();
        return x;

    } else {
        cerr << "Unable to open file " << filename << endl;
        exit(-1);
    }
}