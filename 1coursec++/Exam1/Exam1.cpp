// Exam1.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//
#include <vector>
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <cmath>
#include <fstream>


template<typename T>
T getRandomNumber(T min, T max)
{
	T value;
	value = rand() % (int)pow(10, 2);
	value = min + (value / pow(10, 2)) * (max - min);

	return value;
}

template<class T>
void printMat(std::vector<std::vector<T>> const& mat) {
	std::cout << '\n' << "Current matrix" << '\n';
	for (std::vector<T> row : mat)
	{
		for (T val : row) {
			std::cout << val << " ";
		}
		std::cout << std::endl;
	}
}

template<class T>
void sumOfRows(std::vector<std::vector<T>> const& mat) {
	int i = 1;
	for (std::vector<T> row : mat)
	{
		T res{ 0 };
		for (T element : row) {
			res += element;
		}
		std::cout << "Sum of row #" << i << " = " << res << std::endl;
		++i;
	}
}
template <class T>
std::vector<std::vector<T>> readMatrixFromFile(const std::string& filename, int rows, int cols) {
	std::ifstream file(filename, std::ios::binary);
	std::vector<std::vector<T>> matrix(rows, std::vector<T>(cols));

	if (file.is_open()) {
		for (int i = 0; i < rows; i++)
			for (int j = 0; j < cols; j++)
				file.read(reinterpret_cast<char*>(&matrix[i][j]), sizeof(T));
	}
	file.close();


	return matrix;
}

int main() {
	srand(time(0));
	std::cout << "Enter dimnesion (M x N): " << '\n';
	int M;
	int N;
	std::cin >> M >> N;

	std::vector<std::vector<double>> temp(M, std::vector<double>(N));

	//заполняем массив
	for (int i = 0; i < M; i++)
	{
		for (int j = 0; j < N; j++)
		{
			temp[i][j] = getRandomNumber(0.0, 10.0);
		}

	}



	std::ofstream fout("ex1.txt", std::ios::out | std::ios::binary); //создаем и открываем файл на запись в бинарном режиме

	for (int i = 0; i < M; i++)
	{
		for (int j = 0; j < N; j++)
		{
			fout.write((char*)&temp[i][j], sizeof(double));  //записываем в файл массив
		}

	}
	fout.close();
	printMat(temp);



	std::vector<std::vector<double>> matrix = readMatrixFromFile<double>("ex1.txt", M, N);
	printMat(matrix);
	sumOfRows(matrix);

}