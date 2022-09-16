#include "stdio.h"
int main()
{
	int k;

	printf("Enter a number\n ");
	//scanf_s("%d", &a);

	while (scanf_s("%d", &k) != 1)//Если будет введена буква, выдаст ошибку
	{
		printf("Wrong imput. Try again\n");
		rewind(stdin);
	}


	if (k % 2 == 0) printf("a - chetnoe\n");
	else printf("a - nechetnoe\n");

	getchar();

}
