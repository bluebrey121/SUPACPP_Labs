#pragma once
#include <vector>
#include <string>

std::vector<std::pair<float, float>> readData(std::string filename);

void printData(std::vector<std::pair<float, float>> dataPoints, int N);

std::vector<float> CalculateMagnitudes(std::vector<std::pair<float, float>> dataPoints);

double calculateChiSq(std::vector<std::pair<float, float>> observed, double p, double q);

std::pair<std::string, double> LinearRegression(std::vector<std::pair<float, float>> dataPoints);

void exponentiateDataPoints(std::vector<std::pair<float, float>> dataPoints, int index = 0);

double recursivePower(double x, int n);