/*
Название программы: Graf10

Назначение программы: находить путь передачи книги так,
чтобы она была у всех в руках и вернулась владельцу.

Назначение файла: создать смежную матрицу и найти путь книги.

Автор: Власов Евгений ИВТ-13БО
*/

#include <stdio.h>
#include <locale.h>
#define _CRT_SECURE_NO_WARNINGS
#define N 100

//Создание смежной матрицы
int* CreateAdjacentMatrix(int A[N][N], int n)
{
	// f - числа в матрице (0 - враги (нет связи), 1 - друзья (связь есть))
	// k - коэффициент связей (при чётном N k = N/2; при нечётном N k = 0)
	int f, k = 0;
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
			if (!scanf_s("%d", &f)) {
				printf_s("This is not number\n");
				system("pause");
				exit(0);
			}
			if (!(f == 1 || f == 0)) {
				printf_s("Wrong number\n");
				system("pause");
				exit(0);
			}
			if (f == 1)
				k++;
			else
				k--;
			A[i][j] = f;
			A[j][i] = f;
		}
	}
	//Проверка на правильность ввода матрицы
	if (n % 2 == 0 && k != n / 2) {
			printf_s("Wrong matrix\n");
			system("pause");
			exit(0);
	}
	if (n % 2 != 0 && k != 0) {
			printf_s("Wrong matrix\n");
			system("pause");
			exit(0);
	}
	return A;
}

//Нахождение пути книги
int FindingPaths(int A[N][N], int n)
{
	int book, B[N];
	int i = 0, j = 0, l = 0;
	for (j; l < n - 1; j++) {
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
			exit(0);
		}
	}
	j = 0;
	printf_s("{%d;%d}\n", i, j);
	return 0;
}
