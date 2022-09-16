#include "stdio.h"

int main()
{
	int a, b, k = 0;

	printf("Enter A:\n");
	//scanf_s("%d", &a);

	while (scanf_s("%d", &a) != 1)//Если будет введена буква, выдаст ошибку
	{
		printf("Wrong imput. Try again\n");
		rewind(stdin);
	}


	printf("Enter B:\n");
	//scanf_s("%d", &b);

	while (scanf_s("%d", &b) != 1)//Если будет введена буква, выдаст ошибку
	{
		printf("Wrong imput. Try again\n");
		rewind(stdin);
	}



	while (a >= b) {
		a = a - b;// от большей части отнимаем меньшую и каждый раз прибавляем к колтчеству 1 пока место на большем отрезке не закончится//
		k = k + 1;
	}
	if (a < b) {
		printf("Number of segments B on segment A - %d\n", k);
	}
	return(0);
}

