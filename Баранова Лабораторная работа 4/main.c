#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include"function.h"

int main()
{ srand(time(NULL));
	int Num = 0;
	while (Num != 4) {
		printf("Input number of task(type 4 for exit):\n");
		scanf_s("%d", &Num);
		while (Num < 1 || Num>4){
			rewind(stdin);
			printf("\nErorr: please enter correct data:\n\n");
			scanf_s("%d", &Num);
		}
		system("cls");
		switch (Num){
		case 1:
			firsttask();
			stopandclearconsole();
			break;
		case 2:
			secondtask();
			stopandclearconsole();
			break;
		case 3:
			thirdtask();
			stopandclearconsole();
			break;
		}
	}
	return 0;
}