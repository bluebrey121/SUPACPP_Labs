#include "MyFunctions.h"

// ------------------------------
// Gaussian
// ------------------------------
double MyFunctions::gaussian(double x) {
    double z = (x - mean) / sigma;
    return std::exp(-0.5 * z * z) / (sigma * std::sqrt(2 * M_PI));
}

// ------------------------------
// Cauchy–Lorentz
// ------------------------------
double MyFunctions::cauchy(double x) {
    double z = (x - mean) / gamma;
    return 1.0 / (M_PI * gamma * (1 + z * z));
}

// ------------------------------
// Crystal Ball
// ------------------------------
double MyFunctions::crystalball(double x) {
    double z = (x - mean) / sigma;

    if (z > -alpha) {
        return std::exp(-0.5 * z * z);
    }

    // Tail region
    double A = std::pow(n/alpha, n) * std::exp(-0.5 * alpha * alpha);
    double B = n/alpha - alpha;

    return A * std::pow(B - z, -n);
}

// ------------------------------
// Override FiniteFunction::callFunction
// ------------------------------
double MyFunctions::callFunction(double x) {
    switch (m_ftype) {
    case GAUSSIAN:
        return gaussian(x);

    case CAUCHY:
        return cauchy(x);

    case CRYSTALBALL:
        return crystalball(x);

    default:
        return 0.0;
    }
}
