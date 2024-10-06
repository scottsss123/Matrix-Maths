#include "includes.h";

void userGenMatrix(std::vector<std::vector<float>>& mat, int m, int n, std::string name)
{
	if (mat.size() != 0)
	{
		mat = {};
	}

	std::cout << "input matrix " << name << "\n";

	for (int i = 0; i < m; i++)
	{
		std::vector<float> row;
		
		for (int j = 0; j < n; j++)
		{
			for (int k = 0; k < j; k++)
				std::cout << "  ";

			float num;
			std::cin >> num;
			row.push_back(num);
		}

		mat.push_back(row);
		std::cout << "\n";
	}
	std::cout << "\n";
}

void genRandMatrix(std::vector<std::vector<float>> &mat, int m, int n, float upperBound, float lowerBound)
{
	if (mat.size() != 0)
	{
		mat = {};
	}

	std::random_device rd;
	std::mt19937 gen(rd());

	std::uniform_real_distribution<float> dis(lowerBound, upperBound);

	for (int i = 0; i < m; i++)
	{
		std::vector<float> row;
		for (int j = 0; j < n; j++) {
			row.push_back(std::round(dis(gen)));
		}
		mat.push_back(row);
	}

	return;
}

void outputMatrix(std::vector<std::vector<float>> &mat)
{
	std::cout << std::endl;

	int m = mat.size();
	if (m == 0)
	{
		std::cout << "empty matrix" << std::endl;
		return;
	}

	int n = mat[0].size();

	for (int i = 0; i < m; i++)
	{
		if (mat[i].size() != n)
		{
			std::cout << "matrix not rectangular" << std::endl;
			return;
		}
		for (int j = 0; j < n; j++)
		{
			std::cout << mat[i][j] << "  ";
		}
		std::cout << std::endl;
	}

	return;
}

void multiplyMatrix(std::vector<std::vector<float>>& matA, std::vector<std::vector<float>>& matB, std::vector<std::vector<float>>& matR)
{
	if (matR.size() != 0)
	{
		matR = {};
	}

	int mA = matA.size();
	int mB = matB.size();

	if (mA == 0 || mB == 0)
	{
		std::cout << "\ncannot multiply empty matrix\n" << "mA: " << mA << "\nmB: " << mB << "\n";
		return;
	}

	int nA = matA[0].size();
	int nB = matB[0].size();

	if (nA != mB)
	{
		std::cout << "\ninvalid matrix multiplication\n" << "nA: " << nA << " != mB: " << mB << "\n";
		return;
	}

	for (int i = 0; i < mA; i++)
	{
		std::vector<float> row;
		for (int j = 0; j < nB; j++)
		{
			float sum = 0;
			for (int k = 0; k < mB; k++)
			{
				sum += matA[i][k] * matB[k][j];
			}
			row.push_back(sum);
		}
		matR.push_back(row);
	}
}