#include<iostream>
#include<iomanip>
#include<vector>
#include"fstream"

using Data = std::vector<std::vector<double>>;

namespace regression{
    // declaring a function: read_database
    Data read_database(std::string filepath);
    // declaring a function: hypothesis
    double hypothesis(std::vector<double> theta, std::vector<double> x);
    // declaring a function: cost_function
    double cost_function(Data dataset, std::vector<double> theta);
    // declaring a function: update
    std::vector<double> update(Data dataset, std::vector<double> theta, double lr);
    // declaring a function: linear_regression
    std::vector<double> linear_regression(Data dataset, std::vector<double> init_theta, double lr);
}