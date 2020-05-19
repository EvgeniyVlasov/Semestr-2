#include <stdio.h>
#include <locale.h>
#define _CRT_SECURE_NO_WARNINGS
#define N 100

//Создание смежной матрицы
int* Matrix(int A[N][N], int n)
{
	// f - числа в матрице (0 - враги (нет связи), 1 - друзья (связь есть))
	int f;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (i == j)
			{
				A[i][j] = 0;
				continue;
			}
			if (A[j][i] == 0 || A[j][i] == 1)
				continue;
			printf_s("\n[%d][%d] -> ", i, j);
			scanf_s("%d", &f);
			A[i][j] = f;
			A[j][i] = f;
		}
	}
	return A;
}

//Нахождение путей книги
int Book(int A[N][N], int n)
{
	int book, B[N];
	int i = 0, j = 0, l = 0;
	for (i, j, l; l < n - 1; j++) {
		if (A[i][j] == 1) {
			B[i] = i;
			if (j != B[j]) {
				printf_s("{%d;%d}->", i, j);
				i = j;
				j = -1;
				l++;
			}
		}
		if (j >= n) {
			printf_s("\n%d man has no friends\n", i + 1);
			system("pause");
			return 0;
		}
	}
	j = 0;
	printf_s("{%d;%d}\n", i, j);
	return 0;
}

void main() 
{
	int n, f;
	int A[N][N];
	//Считываем кол-во человек
	printf_s("N:");
	scanf_s("%d", &n);
	if (n > 100 || n <= 1)
	{
		printf_s("Error\n");
		system("pause");
		return 0;
	}
	// Создание смежной матрицы
	Matrix(A, n);
	// Нахождение путей книги
	Book(A, n);	
	system("pause");
}


/* Трудоёмкость: O(n)
* n - размер матрицы смежности
*
* Тесты:

4
1
0
1
1
0
1

2
1

6
1
0
1
0
1
1
0
1
0
1
0
1
1
0
1

5
1
0
0
1
1
0
0
1
0
1

*/
