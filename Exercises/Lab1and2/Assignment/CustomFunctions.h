#pragma once
#include <vector>
#include <string>

std::vector<std::pair<float, float>> readData(std::string filename);

void printData(std::vector<std::pair<float, float>> dataPoints, int N);
void printData(std::vector<double> dataPoints, int N);

std::vector<double> CalculateMagnitudes(std::vector<std::pair<float, float>> dataPoints);

double calculateChiSq(std::vector<std::pair<float, float>> observed, double p, double q);

std::pair<std::string, double> LinearRegression(std::vector<std::pair<float, float>> dataPoints);

std::vector<double> exponentiateDataPoints(std::vector<std::pair<float, float>> dataPoints, int index = 0);

double recursivePower(double x, int n);

std::vector<double> returnExponents(std::vector<std::pair<float, float>> dataPoints);

void saveToFile(std::vector<double> results, std::string name);
void saveToFile(std::pair<std::string, double> results, std::string name);