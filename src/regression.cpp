#include "regression.h"
// Defining a function: read_database
Data regression::read_database(std::string filepath){
    // try to open the file
    std::ifstream ifile{filepath};
    if (ifile.fail()){
        throw std::runtime_error("couldn't open the given directory.");
    }
    // the output of the function
    Data data{};
    //defining the temp variables
    std::string str{};
    std::vector<double> row{};

    std::string str2find{};
    std::string substr{};
    size_t substr_end{};
    std::string* arr{ new std::string[3] };
    
    
    // while loop to read the file line by line
    while(std::getline(ifile, str)){
        // we try to find the indexes of comma, so we can seperate the book's attributes.

        // initalizing
        str2find = str;
        row.clear();
        // finding the 3 first attributes
        for (size_t i{}; i<3; i++){
            substr_end = str2find.find(',');
            substr = str2find.substr(0, substr_end);
            str2find = str2find.substr(substr_end+1, str2find.length()-substr_end-1);
            arr[i] = substr;
            // std::cout<< "substr " << i << " is: " << arr[i] << std::endl;
        }
        // std::cout<< "substr " << 4 << " is: " << str2find << std::endl;
        
        // initializing the row

        row.push_back(std::stod("1"));
        row.push_back(std::stod(arr[0]));
        row.push_back(std::stod(arr[1]));
        row.push_back(std::stod(arr[2]));
        row.push_back(std::stod(str2find));

        // adding the temp row to the vector data
        data.push_back(row);
    }
    ifile.close();
    delete[] arr;
    return data;
}
// Defining a function: hypothesis
double regression::hypothesis(std::vector<double> theta, std::vector<double> x){
    double yhat{};
    if (theta.size() != x.size())
        throw std::logic_error("the sizes do not match!");

    for (size_t i{}; i < theta.size(); i++){
        yhat += theta[i] * x[i];
    }
    return yhat;
}
// Defining a function: cost_function
double regression::cost_function(Data dataset, std::vector<double> theta){
    double cost{};
    std::vector<double> x{1, 0, 0, 0};
    for (size_t i{}; i < dataset.size(); i++) {
        x = {dataset[i][0], dataset[i][1], dataset[i][2], dataset[i][3]};
        cost += (hypothesis(x, theta) - dataset[i][4]) * (hypothesis(x, theta) - dataset[i][4]);
    }
    return cost / 2;
}
// Defining a function: update
std::vector<double> regression::update(Data dataset, std::vector<double> theta, double lr){
    std::vector<double> gradient{0, 0, 0, 0};
    std::vector<double> theta_updated{theta};
    std::vector<double> x{1, 0, 0, 0};

    for (size_t i{}; i < 4; i++) {
        for (size_t j {}; j < dataset.size(); j++) {
            x = {dataset[j][0], dataset[j][1], dataset[j][2], dataset[j][3]};
            gradient[i] += (hypothesis(x, theta) - dataset[j][4]) * dataset[j][i];
        }
        theta_updated[i] = theta_updated[i] - lr * gradient[i];
    }
    return theta_updated;
}
// Defining a function: linear_regression
std::vector<double> regression::linear_regression(Data dataset, std::vector<double> init_theta, double lr){
    int epoch{10000};
    std::vector<double> theta {init_theta};
    std::vector<double> costs{cost_function(dataset, theta), cost_function(dataset, theta)};
    

    for (size_t i{0}; i < epoch; i++) {
        theta = update(dataset, theta, lr);
        costs[1] = costs[0];
        costs[0] = cost_function(dataset, theta);

        std::cout << std::setw(6) << i << "--> cost: " << std::setprecision(3) << costs[0];
        std::cout << "    - reduced cost: " << std::setprecision(3) << costs[1] - costs[0] << std::endl;
    }
    return theta;
}



//***********************************    challenge question:   ***********************************

//     I suppose the best way to pass the arguments is to pass them as reference, 
// because if we pass them by their values, the compiler should copy the dataset into a 
// temporary storage in memory, and it will cost us more time and computational resource as 
// the dataset gets bigger. and they shouldn't be const, because they need to be updated inplace.
// here I didn't implement it using pass by reference approach,
// because i am not a good c++ programmer yet and I was afraid to mess things up ;)