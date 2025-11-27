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
        auto Magnitudes = CalculateMagnitudes(dataPoints);
    }

    char Answer3;
    std::cout << "Do you want to fit a linear regression to points in the file? [y/n]: ";
    std::cin >> Answer3;    

    if (Answer3 == 'y' || Answer3 == 'Y') {
        auto [Equation, ChiSq] = LinearRegression(dataPoints);
        std::cout << "Linear regression: " << Equation << std::endl;
        std::cout << "Chi squared / DoF = "<< ChiSq << std::endl;
    }

    char Answer4;
    std::cout << "Do you want to calculate x^y for all points in the file? [y/n]: ";
    std::cin >> Answer4;

    if (Answer4 == 'y' || Answer4 == 'Y') {
        auto results = returnExponents(dataPoints);
        std::cout << results.size() << std::endl;
        for (int i; i<results.size(); i++) {
            std::cout << results[i] << std::endl;
        }
    }

    return 0;
}
