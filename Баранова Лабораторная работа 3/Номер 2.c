#include <stdio.h>
#include <stdlib.h> 
#include <time.h> 
int main()
{
	int randNumber;
	char resh;
	int n, i, k = 0, p = 0;
	int array[100] = { 0 };
	srand(time(NULL));

	printf("Enter number of elements:");

	while (scanf_s("%d", &n) != 1 || getchar() != '\n' || n <= 0 || n > 100)
	{
		printf("Wrong imput. Try again:");
		rewind(stdin);
	}
	rewind(stdin);

	printf("Would you like to generate random numbers? (y/Y - yes) - ");
	scanf_s("%c", &resh);
	rewind(stdin);
	if (resh == 'y' || resh == 'Y')
	{
		for (i = 0; i < n; i++)
		{
			printf("Number %d - %d\n", i + 1, randNumber = (rand() % 200) - 100);
			array[i] = randNumber;
		}
		for (i = 0; i < n + k; i++)
		{
			if (array[i] < 0)
			{
				k++;
				for (int j = n + k - 1; j > i; j--)
				{
					array[j] = array[j - 1];
				}array[i] = array[i + 1];
				i++;
			}

		}
		printf("\n");

		for (i = 0; i < n + k; i++)
		{
			printf("%d;", array[i]);

		}
		
		
		return 0;
	}
	for (i = 0; i < n; i++)
	{
		printf("Enter number %d:", i + 1);
		while (scanf_s("%d", &array[i]) != 1  || getchar() != '\n'  )
		{
			printf("Wrong imput. Try again:");
			rewind(stdin);
		}
	}

	for (i = 0; i < n + k; i++)
	{
		printf("%d;", array[i]);

	}
	for (i = 0; i < n + k; i++)
	{
		if (array[i] < 0)
		{
			k++;
			for (int j = n + k - 1; j > i; j--)
			{
				array[j] = array[j - 1];
			}array[i ] = array[i+1];
			i++;
		}
		
	}
	printf("\n");
       
	for (i = 0; i < n + k; i++)
	{
		printf("%d;", array[i]);

	}
	return 0;
}