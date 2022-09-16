#include "stdio.h"
int main()
{
	int c, y;
	float m;

	printf("Current year:\n ");
	//scanf_s("%d", &c);

	while (scanf_s("%d", &c) != 1)//Если будет введена буква, выдаст ошибку
	{
		printf("Wrong imput. Try again\n");
		rewind(stdin);
	}
	printf("Year of purchase:\n ");
	//scanf_s("%d", &y);

	while (scanf_s("%d", &y) != 1)//Если будет введена буква, выдаст ошибку
	{
		printf("Wrong imput. Try again\n");
		rewind(stdin);
	}

	printf("original price:\n ");
	//scanf_s("%f", &m);


	while (scanf_s("%f", &m) != 1)//Если будет введена буква, выдаст ошибку
	{
		printf("Wrong imput. Try again\n");
		rewind(stdin);
	}

	while (c > y)
	{
		//printf("Year %d\n", y);//
		y = y + 1;// прибавляем к изначальному году по одному, пока не дойдем до текущего
		//printf("The price is: %.2f\n", m);//
		m = m + (m * 0.04);
	}

	printf("Today, in %d, the cost would be %.2f dollars\n", y, m);
	return 0;
}