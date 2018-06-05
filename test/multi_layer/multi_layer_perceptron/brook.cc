#include "brook.h"

using Brook::Graph;

Graph::Graph()
: brook_variable (2, 8)
, brook_variable_1 (12, 8)
, brook_variable_2 (8, 4)
, brook_variable_3 (12, 4)
, brook_variable_4 (4, 2)
, brook_variable_5 (12, 2)
, brook_variable_6 (2, 2)
, brook_variable_7 (12, 2)
{
    brook_variable(0, 0) = -0.609609;
    brook_variable(0, 1) = -0.421765;
    brook_variable(0, 2) = 0.0376582;
    brook_variable(0, 3) = 0.29946;
    brook_variable(0, 4) = 0.397677;
    brook_variable(0, 5) = -0.822179;
    brook_variable(0, 6) = -0.782539;
    brook_variable(0, 7) = 0.62951;
    brook_variable(1, 0) = -0.854857;
    brook_variable(1, 1) = -0.0756502;
    brook_variable(1, 2) = 0.347594;
    brook_variable(1, 3) = 0.527353;
    brook_variable(1, 4) = 0.440458;
    brook_variable(1, 5) = -0.753287;
    brook_variable(1, 6) = -0.745887;
    brook_variable(1, 7) = -0.133129;
    brook_variable_1(0, 0) = 0.894063;
    brook_variable_1(0, 1) = -0.0282203;
    brook_variable_1(0, 2) = -0.226495;
    brook_variable_1(0, 3) = -0.350595;
    brook_variable_1(0, 4) = -0.568177;
    brook_variable_1(0, 5) = 0.143138;
    brook_variable_1(0, 6) = 0.0200043;
    brook_variable_1(0, 7) = -0.724989;
    brook_variable_1(1, 0) = 0.3835;
    brook_variable_1(1, 1) = 0.104205;
    brook_variable_1(1, 2) = -1.0803;
    brook_variable_1(1, 3) = -0.696861;
    brook_variable_1(1, 4) = -0.936956;
    brook_variable_1(1, 5) = -0.135825;
    brook_variable_1(1, 6) = -0.0362404;
    brook_variable_1(1, 7) = -1.06467;
    brook_variable_1(2, 0) = 0.126402;
    brook_variable_1(2, 1) = 0.0880977;
    brook_variable_1(2, 2) = -0.18219;
    brook_variable_1(2, 3) = -0.355609;
    brook_variable_1(2, 4) = -0.302196;
    brook_variable_1(2, 5) = 0.18256;
    brook_variable_1(2, 6) = -0.0345125;
    brook_variable_1(2, 7) = 0.15416;
    brook_variable_1(3, 0) = -0.197187;
    brook_variable_1(3, 1) = 0.094801;
    brook_variable_1(3, 2) = -0.8968;
    brook_variable_1(3, 3) = -0.224116;
    brook_variable_1(3, 4) = -0.620215;
    brook_variable_1(3, 5) = 0.0172915;
    brook_variable_1(3, 6) = 0.0180387;
    brook_variable_1(3, 7) = 0.0786584;
    brook_variable_1(4, 0) = 0.0364221;
    brook_variable_1(4, 1) = -0.0047491;
    brook_variable_1(4, 2) = -0.598635;
    brook_variable_1(4, 3) = -0.485187;
    brook_variable_1(4, 4) = -0.544055;
    brook_variable_1(4, 5) = -0.108695;
    brook_variable_1(4, 6) = -0.199917;
    brook_variable_1(4, 7) = -0.138407;
    brook_variable_1(5, 0) = 0.0155646;
    brook_variable_1(5, 1) = -0.027173;
    brook_variable_1(5, 2) = -1.44252;
    brook_variable_1(5, 3) = -0.555338;
    brook_variable_1(5, 4) = -1.1419;
    brook_variable_1(5, 5) = 0.069093;
    brook_variable_1(5, 6) = -0.0639692;
    brook_variable_1(5, 7) = 1.85817;
    brook_variable_1(6, 0) = 0.0212482;
    brook_variable_1(6, 1) = 0.0119798;
    brook_variable_1(6, 2) = -1.55204;
    brook_variable_1(6, 3) = -0.318282;
    brook_variable_1(6, 4) = -0.849549;
    brook_variable_1(6, 5) = -0.105764;
    brook_variable_1(6, 6) = -0.111561;
    brook_variable_1(6, 7) = 2.20478;
    brook_variable_1(7, 0) = -0.0554912;
    brook_variable_1(7, 1) = 0.0336811;
    brook_variable_1(7, 2) = 0.124075;
    brook_variable_1(7, 3) = 0.302814;
    brook_variable_1(7, 4) = 0.312862;
    brook_variable_1(7, 5) = -0.0535816;
    brook_variable_1(7, 6) = 0.032255;
    brook_variable_1(7, 7) = -0.0217387;
    brook_variable_1(8, 0) = 0.58349;
    brook_variable_1(8, 1) = 0.645966;
    brook_variable_1(8, 2) = -0.0486039;
    brook_variable_1(8, 3) = 0.418722;
    brook_variable_1(8, 4) = 0.0381695;
    brook_variable_1(8, 5) = 0.742708;
    brook_variable_1(8, 6) = 0.64653;
    brook_variable_1(8, 7) = 0.321968;
    brook_variable_1(9, 0) = 0.00764238;
    brook_variable_1(9, 1) = -0.0481248;
    brook_variable_1(9, 2) = -0.942838;
    brook_variable_1(9, 3) = 0.356273;
    brook_variable_1(9, 4) = -0.772449;
    brook_variable_1(9, 5) = 0.178906;
    brook_variable_1(9, 6) = 0.110514;
    brook_variable_1(9, 7) = 2.65157;
    brook_variable_1(10, 0) = 0.271244;
    brook_variable_1(10, 1) = -0.0799559;
    brook_variable_1(10, 2) = -1.25652;
    brook_variable_1(10, 3) = -0.486732;
    brook_variable_1(10, 4) = -0.925862;
    brook_variable_1(10, 5) = -0.0335245;
    brook_variable_1(10, 6) = -0.0387755;
    brook_variable_1(10, 7) = 1.55376;
    brook_variable_1(11, 0) = -0.131022;
    brook_variable_1(11, 1) = -0.000105493;
    brook_variable_1(11, 2) = 0.715284;
    brook_variable_1(11, 3) = 0.662995;
    brook_variable_1(11, 4) = 0.965193;
    brook_variable_1(11, 5) = 0.153737;
    brook_variable_1(11, 6) = 0.0951637;
    brook_variable_1(11, 7) = 0.202832;
    brook_variable_2(0, 0) = 0.636857;
    brook_variable_2(0, 1) = 0.803495;
    brook_variable_2(0, 2) = -0.207913;
    brook_variable_2(0, 3) = 0.634297;
    brook_variable_2(1, 0) = 0.360633;
    brook_variable_2(1, 1) = 0.0560222;
    brook_variable_2(1, 2) = -0.400567;
    brook_variable_2(1, 3) = 0.61568;
    brook_variable_2(2, 0) = 0.137496;
    brook_variable_2(2, 1) = 0.295114;
    brook_variable_2(2, 2) = -0.0624185;
    brook_variable_2(2, 3) = 0.135048;
    brook_variable_2(3, 0) = 0.398987;
    brook_variable_2(3, 1) = 0.185007;
    brook_variable_2(3, 2) = 0.0974842;
    brook_variable_2(3, 3) = 0.173208;
    brook_variable_2(4, 0) = 0.0953636;
    brook_variable_2(4, 1) = 0.266116;
    brook_variable_2(4, 2) = -0.0725629;
    brook_variable_2(4, 3) = 0.286979;
    brook_variable_2(5, 0) = 0.653368;
    brook_variable_2(5, 1) = 0.655536;
    brook_variable_2(5, 2) = -0.137003;
    brook_variable_2(5, 3) = 0.734256;
    brook_variable_2(6, 0) = 0.699876;
    brook_variable_2(6, 1) = 0.767988;
    brook_variable_2(6, 2) = -0.0792416;
    brook_variable_2(6, 3) = 0.67729;
    brook_variable_2(7, 0) = -0.147184;
    brook_variable_2(7, 1) = -0.0976161;
    brook_variable_2(7, 2) = 0.951013;
    brook_variable_2(7, 3) = 0.055735;
    brook_variable_3(0, 0) = -0.148367;
    brook_variable_3(0, 1) = -0.183938;
    brook_variable_3(0, 2) = 0.238808;
    brook_variable_3(0, 3) = -0.257314;
    brook_variable_3(1, 0) = -0.0297529;
    brook_variable_3(1, 1) = -1.14815;
    brook_variable_3(1, 2) = -0.0347888;
    brook_variable_3(1, 3) = 0.0665369;
    brook_variable_3(2, 0) = -0.745317;
    brook_variable_3(2, 1) = -0.683402;
    brook_variable_3(2, 2) = -0.0572889;
    brook_variable_3(2, 3) = -0.588549;
    brook_variable_3(3, 0) = -1.0647;
    brook_variable_3(3, 1) = -0.574898;
    brook_variable_3(3, 2) = -0.107876;
    brook_variable_3(3, 3) = -0.969775;
    brook_variable_3(4, 0) = -1.01377;
    brook_variable_3(4, 1) = -0.543238;
    brook_variable_3(4, 2) = 0.254724;
    brook_variable_3(4, 3) = -0.945042;
    brook_variable_3(5, 0) = -0.381409;
    brook_variable_3(5, 1) = -0.735835;
    brook_variable_3(5, 2) = 2.72663;
    brook_variable_3(5, 3) = -0.676127;
    brook_variable_3(6, 0) = -0.457649;
    brook_variable_3(6, 1) = -1.30217;
    brook_variable_3(6, 2) = 2.39185;
    brook_variable_3(6, 3) = -0.35211;
    brook_variable_3(7, 0) = 0.203551;
    brook_variable_3(7, 1) = 0.0641707;
    brook_variable_3(7, 2) = -0.0432118;
    brook_variable_3(7, 3) = 0.119774;
    brook_variable_3(8, 0) = 0.847031;
    brook_variable_3(8, 1) = 0.774149;
    brook_variable_3(8, 2) = -0.205026;
    brook_variable_3(8, 3) = 0.816271;
    brook_variable_3(9, 0) = 0.133158;
    brook_variable_3(9, 1) = -0.873188;
    brook_variable_3(9, 2) = 2.64154;
    brook_variable_3(9, 3) = -0.083293;
    brook_variable_3(10, 0) = -1.04085;
    brook_variable_3(10, 1) = -0.43154;
    brook_variable_3(10, 2) = 2.92966;
    brook_variable_3(10, 3) = -0.62399;
    brook_variable_3(11, 0) = 0.597217;
    brook_variable_3(11, 1) = 0.38738;
    brook_variable_3(11, 2) = -0.178022;
    brook_variable_3(11, 3) = 0.311403;
    brook_variable_4(0, 0) = -13.8986;
    brook_variable_4(0, 1) = -13.6122;
    brook_variable_4(1, 0) = -14.0405;
    brook_variable_4(1, 1) = -13.985;
    brook_variable_4(2, 0) = -2.97816;
    brook_variable_4(2, 1) = 4.65114;
    brook_variable_4(3, 0) = -13.9246;
    brook_variable_4(3, 1) = -13.6892;
    brook_variable_5(0, 0) = 1.31683;
    brook_variable_5(0, 1) = 0.474323;
    brook_variable_5(1, 0) = -0.557344;
    brook_variable_5(1, 1) = 1.04735;
    brook_variable_5(2, 0) = 0.0266108;
    brook_variable_5(2, 1) = -0.462877;
    brook_variable_5(3, 0) = -0.0956053;
    brook_variable_5(3, 1) = -0.238529;
    brook_variable_5(4, 0) = 0.529036;
    brook_variable_5(4, 1) = -0.0689588;
    brook_variable_5(5, 0) = 1.38413;
    brook_variable_5(5, 1) = 0.258755;
    brook_variable_5(6, 0) = -5.1111;
    brook_variable_5(6, 1) = 4.68581;
    brook_variable_5(7, 0) = -14.9616;
    brook_variable_5(7, 1) = -15.0627;
    brook_variable_5(8, 0) = 19.2687;
    brook_variable_5(8, 1) = 21.0941;
    brook_variable_5(9, 0) = -9.91165;
    brook_variable_5(9, 1) = 8.19578;
    brook_variable_5(10, 0) = 5.69962;
    brook_variable_5(10, 1) = -3.84323;
    brook_variable_5(11, 0) = -10.0288;
    brook_variable_5(11, 1) = -10.0027;
    brook_variable_6(0, 0) = -2.77838;
    brook_variable_6(0, 1) = -14.0835;
    brook_variable_6(1, 0) = 2.49693;
    brook_variable_6(1, 1) = -14.3376;
    brook_variable_7(0, 0) = -1.88282;
    brook_variable_7(0, 1) = -0.511955;
    brook_variable_7(1, 0) = 1.52742;
    brook_variable_7(1, 1) = -1.88098;
    brook_variable_7(2, 0) = -2.80829;
    brook_variable_7(2, 1) = 1.38708;
    brook_variable_7(3, 0) = -3.28743;
    brook_variable_7(3, 1) = 1.13506;
    brook_variable_7(4, 0) = -2.8967;
    brook_variable_7(4, 1) = 0.867817;
    brook_variable_7(5, 0) = 0.880058;
    brook_variable_7(5, 1) = -0.670935;
    brook_variable_7(6, 0) = 3.59078;
    brook_variable_7(6, 1) = -1.29217;
    brook_variable_7(7, 0) = -4.54984;
    brook_variable_7(7, 1) = 9.3984;
    brook_variable_7(8, 0) = -7.43844;
    brook_variable_7(8, 1) = -17.3311;
    brook_variable_7(9, 0) = 5.65395;
    brook_variable_7(9, 1) = -3.24839;
    brook_variable_7(10, 0) = -3.11171;
    brook_variable_7(10, 1) = -0.775663;
    brook_variable_7(11, 0) = 6.84922;
    brook_variable_7(11, 1) = 5.68791;
    
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

    Eigen::MatrixXd brook_matmul = brook_inputx * brook_variable;
    Eigen::MatrixXd brook_add = add(brook_matmul, brook_variable_1);
    Eigen::MatrixXd brook_relu = brook_add.cwiseMax(0);
    Eigen::MatrixXd brook_matmul_1 = brook_relu * brook_variable_2;
    Eigen::MatrixXd brook_add_1 = add(brook_matmul_1, brook_variable_3);
    Eigen::MatrixXd brook_relu6 = brook_add_1.cwiseMax(0).cwiseMin(6);
    Eigen::MatrixXd brook_matmul_2 = brook_relu6 * brook_variable_4;
    Eigen::MatrixXd brook_add_2 = add(brook_matmul_2, brook_variable_5);
    Eigen::MatrixXd brook_leakyrelu_mul = 0.300000 * brook_add_2;
    Eigen::MatrixXd brook_leakyrelu_maximum = brook_leakyrelu_mul.cwiseMax(brook_add_2);
    Eigen::MatrixXd brook_matmul_3 = brook_leakyrelu_maximum * brook_variable_6;
    Eigen::MatrixXd brook_outputx = add(brook_matmul_3, brook_variable_7);
    return brook_outputx;
    
}
