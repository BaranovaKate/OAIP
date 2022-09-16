#include "stdio.h"
int main()
{
	int a;
	printf("1 - summer\n2 - autumn\n3 - winter\n4 - spring\n");// присваиваем каждому месяцу цифру для более удобного ввода//
	printf("Enter the time of year:");
	//scanf_s("%d", &a);

	while (scanf_s("%d", &a) != 1)//Если будет введена буква, выдаст ошибку
	{
		printf("Wrong imput. Try again\n");
		rewind(stdin);
	}
	switch (a) //сравнивает значение с несколькими константами, может содержат неограниченное число case//
	{
	case 1:// если введена цифра 1, то будут выведены месяца поры года под номером 1//
		printf("June, July, August\n");
		break;
	case 2:
		printf("September, October, November\n");
		break;
	case 3:
		printf("December, January, February\n");
		break;
	case 4:
		printf("March, April, May\n");
		break;
	default: printf("Mistake\n");//Если введена цифра, которой не присвоено время года выписывается ошибка//
		return 0;
	}
}
