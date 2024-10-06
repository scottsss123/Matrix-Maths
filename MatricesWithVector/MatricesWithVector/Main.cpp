#include "includes.h"
#include "Matrix.h"

int main(int argc, char** argv)
{
	const float upperBound = 10.0f;
	const float lowerBound = 0.0f;

	int mA, nA, mB, nB;
	
	std::cout << "Enter matrices' orders:\n\nmatA:\nrows: ";
	std::cin >> mA;
	std::cout << "columns: ";
	std::cin >> nA;
	std::cout << "matB:\nrows: ";
	std::cin >> mB;
	std::cout << "columns: ";
	std::cin >> nB;

	//const int mA = 3;
	//const int nA = 2;
	std::vector<std::vector<float>> matA;
	//genRandMatrix(matA, mA, nA, upperBound, lowerBound);
	userGenMatrix(matA, mA, nA, "A");

	//const int mB = 2;
	//const int nB = 3;
	std::vector<std::vector<float>> matB;
	//genRandMatrix(matB, mB, nB, upperBound, lowerBound);
	userGenMatrix(matB, mB, nB, "B");

	std::cout << "\nmatA:";
	outputMatrix(matA);
	std::cout << "matB:";
	outputMatrix(matB);

	std::vector<std::vector<float>> matAmatB;
	std::cout << "\nmatAmatB:";
	multiplyMatrix(matA, matB, matAmatB);
	outputMatrix(matAmatB);
}