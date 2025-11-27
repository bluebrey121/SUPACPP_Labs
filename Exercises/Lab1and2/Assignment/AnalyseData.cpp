#include <iostream>
#include <fstream>
#include "CustomFunctions.h"

int main() {
    // Read data from file to container
    std::string filename = "../input2D_float.txt";
    auto dataPoints = readData(filename);

    char Answer1;
    std::cout << "Do you want to print any lines from the file? [y/n]: ";
    std::cin >> Answer1;

    if (Answer1 == 'y' || Answer1 == 'Y') {
        // Prompt for number of rows to print
        int N;
        std::cout << "Enter number of lines to print: ";
        std::cin >> N;
        printData(dataPoints, N);
    }

    char Answer2;
    std::cout << "Do you want to calculate the magnitude of points in the file? [y/n]: ";
    std::cin >> Answer2;

    if (Answer2 == 'y' || Answer2 == 'Y') {
        // Calculate magnitudes of data points
        auto Magnitudes = CalculateMagnitudes(dataPoints);
        // Print results to terminal
        printData(Magnitudes, Magnitudes.size()); // print all data
        // Save magnitudes to file
        saveToFile(Magnitudes, "magnitudes");
    }

    char Answer3;
    std::cout << "Do you want to fit a linear regression to points in the file? [y/n]: ";
    std::cin >> Answer3;    

    if (Answer3 == 'y' || Answer3 == 'Y') {
        // Fit linear regression to data points
        auto [Equation, ChiSq] = LinearRegression(dataPoints);
        // Print fit parameters to terminal
        std::cout << "Linear regression: " << Equation << std::endl;
        std::cout << "Chi squared / DoF = "<< ChiSq << std::endl;
        // Save linear regression parameters to file
        saveToFile({Equation, ChiSq}, "LinearRegression");
    }

    char Answer4;
    std::cout << "Do you want to calculate x^y for all points in the file? [y/n]: ";
    std::cin >> Answer4;

    if (Answer4 == 'y' || Answer4 == 'Y') {
        // Calculate x^y for all data points
        auto results = returnExponents(dataPoints);
        // Print results to terminal
        printData(results, results.size()); // print all data
        // Save results to file
        saveToFile(results, "exponents");
    }

    return 0;
}
