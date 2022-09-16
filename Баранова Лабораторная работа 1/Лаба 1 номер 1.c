#include "stdio.h"
int main()
{
	int r;
	double S, V;
	const double pi = 3.14;

	printf("Enter the radius of the sphere:\n ");
	while (scanf_s("%d", &r) != 1)//Если будет введена буква, выдаст ошибку
	{
		printf("Wrong imput. Try again\n");
		rewind(stdin);
	}

	S = 4 * pi * r * r;
	V = (4 * pi * r * r * r) / 3;

	printf("The surface area of the sphere = %.2f\nThe volume of the sphere = %.2f\n", S, V);// %.2f   f показывает что число дробное, а 2 это количество цифр после запятой// 
	return 0;
}
