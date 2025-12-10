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

    // --- 3. Tell FiniteFunction to plot the function as well ---
    F.plotFunction();   // scans function over range and stores (x,f(x))

    // --- 4. Tell FiniteFunction to turn the data into a histogram ---
    // Choose an appropriate number of bins, e.g., 50
    F.plotData(dataPoints, 50, true);

    // --- 5. Print extra debugging info (optional) ---
    F.printInfo();

    // --- 6. Program ends → FiniteFunction destructor runs ---
    // This automatically generates the PNG in Outputs/png/

    return 0;
}