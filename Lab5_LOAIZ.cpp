#define _CRT_SECURE_NO_WARNINGS

#include <queue>
#include <iostream>
#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <locale.h>

using namespace std;

queue <int> q; //Объявляем очередь

void BFS(int v, int** M, int* Vis, int Size)
{
	int i;

	q.push(v); Vis[v] = 1;

	while (!q.empty()) //Выполняем код, пока очередь не пуста
	{
		v = q.front(); //Устанавливаем текущую вершину

		q.pop(); //Извлекаем номер веришны из очереди

		printf("%2d", v + 1);

		for (i = 0; i < Size; i++)
		{
			if ((Vis[i] == 0) && (M[v][i] == 1)) 
			{
				q.push(i);
				Vis[i] = 1;
			}
		}
	}
}

void main()
{
	int** G = NULL, i = 0, j = 0, S = 0, * Visited = NULL, N;
	char ReVis = 0;	//Индикатор ранее посещённой вершины

	setlocale(LC_ALL, "Rus");
	srand(time(NULL));

	printf("Введите размерность матрицы: ");
	scanf("%d", &S);
	
	while (S <= 0) //Проверка корректности ввода размера матрицы смежности
	{
		printf("Ошибка при выполнении запроса! Введите целое положительное число : ");
		scanf("%d", &S);
	}

	G = (int**)malloc(S * sizeof(int)); //Выделяем память
	Visited = (int*)malloc(S * sizeof(int));

	for (i = 0;i < S;i++) //Помечаем все вершины как непосещённые
		Visited[i] = 0;

	for (i = 0;i < S;i++) //Генерируем матрицу смежности графа
	{
		G[i] = (int*)malloc(S * sizeof(int));
		for (j = 0;j < S;j++)
		{
			G[i][j] = rand() % 2;
			if (G[i][i] != 0)
				G[i][j] = 0;
		}
	}

	for (i = 0;i < S;i++) //Выводим матрицу смежности на экран
	{
		printf("\n");

		for (j = 0;j < S;j++)
		{
			G[j][i] = G[i][j];
			printf("%2d", G[i][j]);
		}
	}

	printf("\n\nВведите вершину, с которой следует начать обход в ширину: "); 
	scanf("%d", &N);
	
	while (N<1 || N>S) //Проверяем корректность ввода вершины, с которой нужно начать обход

	{
		printf("\nОшибка при выполнении запроса!\nВведите целое положительное число в пределах размера матрицы: ");
		scanf("%d", &N);

	}

	printf("\nОбход графа в ширину: ");

	BFS(N - 1, G, Visited, S); //Вызываем функцию обхода графа в ширину

	printf("\n");

	free(Visited); //Очистка памяти
	free(G);
}
