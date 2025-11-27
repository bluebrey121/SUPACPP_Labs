#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>
#include <utility>
# include <cmath>

// Function to read data from file and load it into container
std::vector<std::pair<float, float>> readData(std::string filename) {

    // Open file.
    std::ifstream inputFile(filename);
    // Declare container to store data.
    std::vector<std::pair<float, float>> dataPoints;

    // Check if file is open. If not print error.
    if (!inputFile.is_open()) {
        std::cerr << "Error: Could not open file " << filename << std::endl;
        return dataPoints;
    }

    std::string line;
    // Skip header
    if (!std::getline(inputFile, line)) {
        std::cerr << "Error: File is empty or missing header." << std::endl;
        return dataPoints;
    }

    // Loop as long as there are more lines
    while (std::getline(inputFile, line)) {
        
        std::stringstream ss(line);
        std::string xStr, yStr;

        if (std::getline(ss, xStr, ',') && std::getline(ss, yStr)) {
            // Convert strings to floats
            float x = std::stof(xStr);
            float y = std::stof(yStr);
            dataPoints.emplace_back(x, y);
        }
    }

    return dataPoints;
}

// Function to print data to the terminal from container
void printData(std::vector<std::pair<float, float>> dataPoints, int N) {

    // Check if there is any data to display
    int total = dataPoints.size();
    if (total == 0) {
        std::cout << "No data to display." << std::endl;
        return;
    }

    // Check if there is enough data to display. If not display 5 data points
    if (N > total) {
        std::cout << "Warning: Requested " << N << " lines, but only " << total << " available." << std::endl;
        std::cout << "Printing first 5 lines instead:" << std::endl;
        N = std::min(5, total);
    }

    for (int i = 0; i < N; ++i) {
        std::cout << "(" << dataPoints[i].first << ", " << dataPoints[i].second << ")" << std::endl;
    }
}

// Fuction which calculates magnitude
std::vector<double> CalculateMagnitudes(std::vector<std::pair<float, float>> dataPoints) {
    std::vector<double> Magnitudes;
    int total = dataPoints.size();

    for(int i=0; i<total; i++) {
        double Magnitude = sqrt(dataPoints[i].first*dataPoints[i].first + dataPoints[i].second*dataPoints[i].second);
        Magnitudes.emplace_back(Magnitude);
        std::cout << Magnitude << std::endl;
    }
    return Magnitudes;
}

// Calculate Chi squared
double calculateChiSq(std::vector<std::pair<float, float>> observed, double p, double q) {
    //Load error data 
    auto errors = readData("../error2D_float.txt");

    int total = observed.size();
    
    double ChiSq;
    
    for (int i=0; i<total; i++) {
        double x = observed[i].first;
        double y = observed[i].second;
        double sigma = errors[i].second;

        double expected = p*x + q;

        ChiSq += (y-expected)*(y-expected) / (sigma*sigma);
    }

    ChiSq /= total-2; //Normalise chi squared.

    return ChiSq;
}

// Function to fit linear regression on data
std::pair<std::string, double> LinearRegression(std::vector<std::pair<float, float>> dataPoints) {
    int total = dataPoints.size();

    float y_sum = 0;
    float x_sum = 0;
    float x_sq_sum = 0;
    float xy_sum = 0;

    for (int i=0; i<total; i++) {
        float x = dataPoints[i].first;
        float y = dataPoints[i].second;

        x_sum += x;
        y_sum += y;
        x_sq_sum += x*x;
        xy_sum += x*y;
    }

    float p = (total*xy_sum - x_sum*y_sum) / (total*x_sq_sum - x_sum*x_sum);
    float q = (x_sq_sum*y_sum - xy_sum*x_sum) / (total*x_sq_sum - x_sum*x_sum);

    std::string Equation = "y= " + std::to_string(p) +  "*x + "  + std::to_string(q);

    //std::ofstream EquationFile("Equation.txt");
    //EquationFile << Equation << std::endl;

    auto ChiSq = calculateChiSq(dataPoints, p, q);

    //EquationFile << ChiSq;

    return {Equation, ChiSq};
}

// Recursive function to compute x^n
double recursivePower(double x, int n) {
    // base case
    if (n == 0) return 1;
    // recursive step
    return x * recursivePower(x, n - 1); 
}

// Recursive function to process each data point
void exponentiateDataPoints(std::vector<std::pair<float, float>> dataPoints, std::vector<double>& results, int index) {

    // base case: end of vector
    if (index >= dataPoints.size()) {
        return;
    }

    double x = dataPoints[index].first;
    double y = dataPoints[index].second;   

    int yRounded = std::round(y);  // round y to nearest integer
    results.push_back(recursivePower(x, yRounded));

    // recursive call for next element
    exponentiateDataPoints(dataPoints, results, index + 1);
}

// Function that returns a vector of results for printing and writing to file
std::vector<double> returnExponents(std::vector<std::pair<float, float>> dataPoints) {
    std::vector<double> results;
    exponentiateDataPoints(dataPoints, results, 0);
    return results;
}

// Saving function overload for magnitudes / exponents
void saveToFile(std::vector<double> results, std::string name) {
    std::ofstream file("../Outputs/" + name + ".txt");
    if (!file) {
        std::cerr << "Error opening file" << std::endl;
        return;
    }
    for (double val : results) {
        file << val << std::endl;  // each value on a new row
    }
    file.close();
}

// Saving function overload for linear regression
void saveToFile(std::pair<std::string, double> results, std::string name) {
    std::ofstream file("../Outputs/" + name + ".txt");
    if (!file) {
        std::cerr << "Error opening file" << std::endl;
        return;
    }
    // Add string equation to file
    file << results.first << std::endl;
    // Add double Chi sq value to file
    file << results.second;
    file.close();
}
