#include<stdio.h>
#include"function.h"
#include<stdlib.h>

int check(int a)
{
	int sight;
	if (a != 0)
		scanf_s("%d", &sight);
	if (a == 1) {
		while (getchar() != '\n' || sight != (int)sight || sight > 100 || sight <= 1)// sight != (int)sight другой способ проверки scanf() !=1, показывает принадлежность к типу int
		{
			rewind(stdin);
			printf("\nWrong imput. Try again\n");
			scanf_s("%d", &sight);
		}
		return sight;
	}
	if (a == 0) {
		long long tmp;//выделение места, 19 знаков
		scanf_s("%10lld", &tmp);
		while (getchar() != '\n' || tmp != (int)tmp)
		{
			rewind(stdin);
			printf("\nWrong imput. Try again\n");
			scanf_s("%10lld", &tmp);

		}
		sight = tmp;
		return sight;
	} 
	if (a == 2)
	{
		while (getchar() != '\n' || a < 1 || a>2)
		{
			rewind(stdin);
			printf("\nWrong imput. Try again\n");
			scanf_s("%d", &sight);

		}
		return sight;
	}
}
void stopandclearconsole()
{
	rewind(stdin);//очистка потока
	getchar();//останавливает консоль
	system("cls");//чистит  консоль
}
int SizeArr(int a)
{
	int n;
	if (a == 1) {
		printf("input amount of rows of the  matrix\n");
	}
	if (a == 2) {
		printf("input samount of coumns of the  matrix\n");
	}
if(a==3) {
	printf("input size of the square matrix\n");
}
		n = check(1);
		return n;

}
void Input(int mas[100][100], int n, int k)
{
	int a;
	printf("Choose:\n1)random input\n2)custom input\n");
	a = check(2);
	while (a < 1 || a >2)
	{
		printf("Wrong imput. Try again\n");
		a = check(2);
	}

	if (a == 1)
	{
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < k; j++) {

				mas[i][j] = (rand() % 20) - 10;
			}
		}
	}
	if (a == 2)
	{
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < k; j++) {
				printf("Input  element of arr:\n");
				mas[i][j] = check(0);
			}
		}
	}

}
void Output(int arr[100][100], int n, int k)
{
	printf("Matrix:\n");
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < k; j++) {
			printf("%d\t", arr[i][j]);
		}
		printf("\n");
	}

}
int Index(int arr[100][100], int n, int k)//?
{
	int min, index = 0, amount = 0;
	for (int i = 0; i < n; i++)
	{
		min = arr[i][0];
		for (int j = 0; j < k; j++)
		{
			if (min < arr[i][j])
			{
				min = arr[i][j];
				amount++;
			}
			if (amount == k - 1)
			{
				index = i;// нумерация строк начинается с 0. Нашли нужную строку, записали и отправили в цикл
				return index;
			}

		}
		amount = 0;
	}
	return -1;//Если у нас нет нужных строк, функция пойдет не в if, а в else
}

void firsttask()
{
	int arr[100][100];
	int n, sum = 0, min, max;
	n = SizeArr(3);
	Input(arr, n,n);
	Output(arr, n,n);


	for (int i = 0; i < n; i++)
	{
		min = arr[i][0];
		max = arr[i][0];
		if (i % 2 == 1)
		{
			for (int j = 0; j < n; j++)
			{

				if (max < arr[i][j])
				{
					max = arr[i][j];
				}
			}
			sum += max;
		}

		if (i % 2 == 0)
		{
			for (int j = 0; j < n; j++)
			{
				if (min > arr[i][j])
				{
					min = arr[i][j];
				}
			}
			sum += min;
		}

	}
	printf("Sum:  %d", sum);

}

void secondtask()
{
	int arr[100][100];
	int n,k, index;
	n = SizeArr(1);
	k = SizeArr(2);
	Input(arr, n,k);
	Output(arr, n,k);
	index = Index(arr, n,k);

	if (index != -1) 
	{
		for (int j = 0; j < k / 2; j++)
		{
			int p;
			p = arr[index][j];// номер строки которую запомнили в void index
			arr[index][j] = arr[index][k - 1 - j];
			arr[index][k - 1 - j] = p;
		}

		printf("\nNew\n");
		Output(arr, n,k);
	}
	else
		printf("\nThere is no ascending row here");

}

void thirdtask()
{
	int arr[100][100], sum = 0;
	int n; 
	n = SizeArr(3);
	Input(arr, n,n);
	Output(arr, n,n);
	if (n % 2)
	{
		for (int j = 0; j < n; j++)
		{
			if (j <= n / 2)
			{
				for (int i = n - 1; i >= n - 1 - j; i--)
				{
					sum += arr[i][j];
				}
			}
			else
			{
				for (int i = n - 1; i >= j; i--)
				{
					sum += arr[i][j];
				}
			}

		}
	}
	else
	{
		for (int j = 0; j < n; j++)
		{
			if (j <= (n / 2) - 1)
			{
				for (int i = n - 1; i >= n - 1 - j; i--)
				{
					sum += arr[i][j];
				}
			}
			else
			{
				for (int i = n - 1; i >= j; i--)
				{
					sum += arr[i][j];
				}
			}

		}
	}
	printf("\nSum: %d", sum);
}
