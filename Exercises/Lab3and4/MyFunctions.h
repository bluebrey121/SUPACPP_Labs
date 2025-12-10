#ifndef MYFUNCTIONS_H
#define MYFUNCTIONS_H

#include "FiniteFunctions.h"
#include <cmath>

class MyFunctions : public FiniteFunction {
public:
    // Constructor: use FiniteFunction’s constructors
    MyFunctions() : FiniteFunction() {}
    MyFunctions(double rmin, double rmax, std::string outfile)
        : FiniteFunction(rmin, rmax, outfile) {}

    // Enumeration to choose the function
    enum FuncType { GAUSSIAN, CAUCHY, CRYSTALBALL };

    // Set which function to use
    void setFunctionType(FuncType t) { m_ftype = t; }

    // Override callFunction to evaluate the chosen function
    double callFunction(double x) override;

    // Parameters for each function
    double mean = 0.0;
    double sigma = 1.0;

    // Cauchy width parameter
    double gamma = 1.0;

    // Crystal Ball parameters
    double alpha = 1.5;
    double n = 2.0;

private:
    FuncType m_ftype = GAUSSIAN;

    // Individual function implementations
    double gaussian(double x);
    double cauchy(double x);
    double crystalball(double x);
};

#endif
