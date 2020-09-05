﻿#include <iostream>
#include <queue> 
#include <fstream>

using namespace std;

int breadth_first_search(int start, int end, int** adjacency_matrix, int N);

int main()
{
	//реализован ввод из файла
	ofstream fout;
	fout.open("OUTPUT.txt");
	ifstream fin;
	fin.open("INPUT.txt");

	//ввод размерности
	int N;
	fin >> N;

	//ввод матрицы смежности
	int** adjacency_matrix;
	adjacency_matrix = new int* [N];
	for (int i = 0; i < N; i++)
	{
		adjacency_matrix[i] = new int[N];
		for (size_t j = 0; j < N; j++)
		{
			fin >> adjacency_matrix[i][j];
		}
	}

	//ввод вершин
	int start, end;
	fin >> start >> end;

	//вывод в файл
	fout << breadth_first_search(start, end, adjacency_matrix, N);

	fout.close();
	fin.close();
	return 0;
}
/*
	\brief Находит минимальное расстояние от двух вершин по алгоритму BFS
	Работает только с корректными данными, то есть введенные вершины существуют в графе

	\param[in] start Начальная вершина
	\param[in] end Конечная вершина
	\param[in] adjacency_matrix Матрица смежности
	\param[in] N Размерность матрицы

	\return Возвращает минимальное расстояние в виде типа int

*/
int breadth_first_search(int start, int end, int** adjacency_matrix, int N)
{
	queue <int> q;

	int* lenght = new int[N];

	//задаем стартовые значения
	for (int i = 0; i < N; i++)
	{
		lenght[i] = -1;
	}
	q.push(start - 1);

	lenght[start - 1] = 0;

	while (!q.empty())
	{
		int i = q.front();
		q.pop();

		for (int j = 0; j < N; j++)
		{
			if (adjacency_matrix[i][j] == 1)
			{
				if (lenght[j] == -1 && i != j)
				{
					q.push(j);
					lenght[q.back()] = lenght[i] + 1;
				}

			}
		}
	}
	if (start == end) lenght[end - 1] = 0;

	return lenght[end - 1];
}


