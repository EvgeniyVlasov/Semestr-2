#include <stdio.h>
#include <locale.h>
#define _CRT_SECURE_NO_WARNINGS
#define N 100

void main() 
{
	int n, f;
	int A[N][N];
	//Считываем кол-во человек и проверяем правильность ввода
	printf_s("N:");
	if(!scanf_s("%d", &n)) {
		printf_s("This is not number\n");
		system("pause");
		exit(0);
	}
	if (n > 100 || n <= 1)
	{
		printf_s("Wrong number\n");
		system("pause");
		exit(0);
	}
	// Создание смежной матрицы
	CreateAdjacentMatrix(A, n);
	// Нахождение путей книги
	FindingPaths(A, n);	
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
