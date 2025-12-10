#include <iostream>
#include <fstream>
#include <vector>
#include "FiniteFunctions.h"

int main() {

    // Create default FiniteFunction object
    FiniteFunction F;
    
    // Load a data file
    std::ifstream infile("../../Data/MysteryData20000.txt");
    if (!infile.is_open()) {
        std::cerr << "Could not open data file!" << std::endl;
        return 1;
    }

    std::vector<double> dataPoints;
    double x;
    while (infile >> x) {
        dataPoints.push_back(x);
    }
    infile.close();

    // Plot the function as well
    F.plotFunction();

    // Turn the data into a histogram
    F.plotData(dataPoints, 50, true); // 50 bins

    // Print extra debugging info ust in case
    F.printInfo();
    
    return 0;
}