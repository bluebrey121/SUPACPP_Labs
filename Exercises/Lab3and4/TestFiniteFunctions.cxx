#include <iostream>
#include <fstream>
#include <vector>
#include "MyFunctions.h"

using namespace std;

// Function to load datapoints from a text file
bool loadData(const string &fname, vector<double> &data) {
    ifstream infile(fname);
    if (!infile.is_open()) {
        cerr << "ERROR: Could not open data file: " << fname << endl;
        return false;
    }
    double x;
    while (infile >> x) data.push_back(x);
    return true;
}

int main() {

    // -----------------------------------------------------------
    // Load datapoints (same for all plots)
    // -----------------------------------------------------------
    vector<double> dataPoints;
    string fname = "../../Data/MysteryData20000.txt";
    if (!loadData(fname, dataPoints)) return 1;

    int Nbins = 50;   // histogram bins

    // -----------------------------------------------------------
    // Gaussian
    // -----------------------------------------------------------
    {
        MyFunctions G(-5, 5, "Gaussian");
        G.setFunctionType(MyFunctions::GAUSSIAN);

        // parameters
        G.mean  = 0.0;
        G.sigma = 1.0;

        // create the curve
        G.plotFunction();

        // plot the datapoints
        G.plotData(dataPoints, Nbins, true);

        G.printInfo();

    }

    // -----------------------------------------------------------
    // Cauchy–Lorenz
    // -----------------------------------------------------------
    {
        MyFunctions C(-10, 10, "Cauchy");
        C.setFunctionType(MyFunctions::CAUCHY);

        C.mean  = 0.0;
        C.gamma = 1.0;

        C.plotFunction();
        C.plotData(dataPoints, Nbins, true);

        C.printInfo();

    }


    // -----------------------------------------------------------
    // Crystal ball
    // -----------------------------------------------------------
    {
        MyFunctions CB(-5, 5, "CrystalBall");
        CB.setFunctionType(MyFunctions::CRYSTALBALL);

        CB.mean  = 0.0;
        CB.sigma = 1.0;
        CB.alpha = 1.5;
        CB.n     = 3.0;

        CB.plotFunction();
        CB.plotData(dataPoints, Nbins, true);

        CB.printInfo();

    }

    return 0;
}
