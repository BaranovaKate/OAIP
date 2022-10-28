#include <stdio.h> 
#include <stdlib.h> 
#include <time.h> 
int main()
{
    int randNumber;
    char resh;
    int n, i, q = 0, sum = 0;
    int array[100] = { 0 };
    srand(time(NULL));
    printf("Enter number of elements: ");
    while (scanf_s("%d", &n) != 1 || n <= 0 || getchar() != '\n' || n > 100)
    {
        printf("Wrong imput. Try again\n");
        rewind(stdin);
    }
    rewind(stdin);
    int max = array[0];
    printf("do you want to generate random numbers?(y/Y - yes) ");

    scanf_s("%c", &resh);
    rewind(stdin);
    if (resh == 'y' || resh == 'Y')
    {
        for (i = 0; i < n; i++)
        {
            printf("\n%d; ", randNumber = (rand() % 200) - 100);
            array[i] = randNumber;

            if (array[i] > max) {
                max = array[i];
            }
        }

        for (i = 0; i < n; i++)
        {
            if (array[i] > 0)
            {
                q = i;
            }
        }

        for (i = 0; i < q; i++)
        {
            sum += array[i];
        }

        printf("\nMax number: %d", max);
        printf("\nSum: %d", sum);
        return 0;
    }
    for (i = 0; i < n; i++)
    {
        printf("Enter number %d:\n", i + 1);
        while (scanf_s("%d", &array[i]) != 1 || getchar() != '\n')
        {
            printf("Wrong imput. Try again\n");
            rewind(stdin);
        }
        if (array[i] > max)
            max = array[i];
        rewind(stdin);
    }
    printf("Max number:%d\n", max);

    for (i = 0; i < n; i++)
    {
        if (array[i] > 0)
        {
            q = i;
        }
    }
    for (i = 0; i < q; i++)
    {
        sum += array[i];
    }
    printf("Sum:%i\n", sum);
    return 0;
}

