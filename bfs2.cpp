#include <iostream>
#include <queue> 
#include <fstream>

using namespace std;


int main()
{
	ofstream fout;
	fout.open("OUTPUT.txt");
	ifstream fin;
	fin.open("INPUT.txt");
	//ввод вершин
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

	
	int start, end;
	fin >> start >> end;

	queue <int> q;

	int* lenght = new int[N];
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
 				if (lenght[j] == -1 && i!=j)
				{
					q.push(j);
					lenght[q.back()] = lenght[i]+1;
				}

			}
		}
	}
	if (start == end) lenght[end - 1] = 0;
	
	fout << lenght[end - 1];
	fout.close();
	fin.close();
	return 0;
}


