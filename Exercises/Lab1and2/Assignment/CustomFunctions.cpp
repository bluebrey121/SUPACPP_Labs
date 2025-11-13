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
std::vector<float> CalculateMagnitudes(std::vector<std::pair<float, float>> dataPoints) {
    std::vector<float> Magnitudes;
    int total = dataPoints.size();

    for(int i=0; i<total; i++) {
        float Magnitude = sqrt(dataPoints[i].first*dataPoints[i].first + dataPoints[i].second*dataPoints[i].second);
        Magnitudes.emplace_back(Magnitude);
        std::cout << Magnitude << std::endl;
    }
    return Magnitudes;
}

// Function to fit linear regression on data
std::string LinearRegression(std::vector<std::pair<float, float>> dataPoints) {
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

    std::ofstream EquationFile("Equation.txt");
    EquationFile << Equation;

    return Equation;
}