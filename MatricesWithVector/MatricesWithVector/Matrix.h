#pragma once

void userGenMatrix(std::vector<std::vector<float>>& mat, int m, int n, std::string name);
void genRandMatrix(std::vector<std::vector<float>> &mat, int m, int n, float upperBound, float lowerBound);
void outputMatrix(std::vector<std::vector<float>> &mat);
void multiplyMatrix(std::vector<std::vector<float>>& matA, std::vector<std::vector<float>>& matB, std::vector<std::vector<float>>& matR);