#pragma once
#include <vector>
#include <string>

std::vector<std::pair<float, float>> readData(std::string filename);
void printData(std::vector<std::pair<float, float>> dataPoints, int N);
std::vector<float> CalculateMagnitudes(std::vector<std::pair<float, float>> dataPoints);
std::string LinearRegression(std::vector<std::pair<float, float>> dataPoints);