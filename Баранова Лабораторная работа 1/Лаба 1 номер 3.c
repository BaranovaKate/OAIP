#include "stdio.h"

int func(float a, float b) {
	return a * b == 1.0f;//a * b = 1, то числа взаимно обратные. f сокращение от float//
}
int main()
{
	float a, b, c;//числа могут быть дробными//
	int cnt;

	printf("numbers (a, b, c): \n ");
	scanf_s("%f %f %f", &a, &b, &c);


	cnt = func(a, b) + func(a, c) + func(b, c);
	printf("result = %d\n", cnt);
	return 0;
}
