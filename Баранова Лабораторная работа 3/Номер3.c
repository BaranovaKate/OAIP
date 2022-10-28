#include <stdio.h> 
#include <stdlib.h>
#include <time.h> 

int main() {
    int randNumber;
    char resh;
    int n1, n2 = 0, n3 = 0, i, j = 0, j1 = 0, tmp;
    int array1[100] = { 0 };
    int array2[100] = { 0 };
    int array3[100] = { 0 };
    srand(time(NULL));

    printf("\nEnter number of elements for array 1: ");
    while (scanf_s("%d", &n1) != 1 || n1 <= 0 || getchar() != '\n' || n1 > 100)
    {
        printf("Wrong imput. Try again:");
        rewind(stdin);
    }
    rewind(stdin);

    printf("Would you like to generate random numbers? (y/Y - yes) - ");
    scanf_s("%c", &resh);
    if (resh == 'y' || resh == 'Y')
    {
        for (i = 0; i < n1; i++)
        {
            printf("Number %d - %d\n", i + 1, randNumber = (rand() % 200) - 100);
            array1[i] = randNumber;
        }
    }
    else
    {
        for (i = 0; i < n1; i++)
        {
            printf("\nEnter number %d: ", i + 1);
            while (scanf_s("%d", &array1[i]) != 1 || getchar() != '\n')
            {
                printf("Wrong imput. Try again:");
                rewind(stdin);
            }
            rewind(stdin);
        }
    }
    for (i = 0; i < n1 - 1; i++)
    {
        for (j = 0; j < n1 - i - 1; j++)
        {
            if (array1[j] > array1[j + 1])
            {
                tmp = array1[j];
                array1[j] = array1[j + 1];
                array1[j + 1] = tmp;
            }
        }
    }
    printf("\nNumbers sorted: ");

    for (i = 0; i < n1; i++)
    {
        printf("%d; ", array1[i]);
    }

    printf("\nEnter number of elements for array 2: ");
    while (scanf_s("%d", &n2) != 1 || n2 < 0 ||  getchar() != '\n' || n2 > 100)
    {
        printf("Wrong imput. Try again:");
        rewind(stdin);
    }
    rewind(stdin);

    printf("Would you like to generate random numbers? (y/Y - yes) - ");
    scanf_s("%c", &resh);
    if (resh == 'y' || resh == 'Y')
    {
        for (i = 0; i < n2; i++)
        {
            printf("Number %d - %d\n", i + 1, randNumber = (rand() % 200) - 100);
            array2[i] = randNumber;
        }
    }
    else {
        for (i = 0; i < n2; i++)
        {
            printf("\nEnter number %d: ", i + 1);
            while (scanf_s("%d", &array2[i]) != 1  || getchar() != '\n' )
            {
                printf("Wrong imput. Try again:");
                rewind(stdin);
            }
            rewind(stdin);
        }
    }
    for (i = 0; i < n2 - 1; i++)
    {
        for (j = 0; j < n2 - i - 1; j++)
        {
            if (array2[j] < array2[j + 1])
            {
                tmp = array2[j];
                array2[j] = array2[j + 1];
                array2[j + 1] = tmp;
            }
        }
    }
    printf("\nNumbers sorted: ");

    for (i = 0; i < n2; i++)
    {
        printf("%d; ", array2[i]);
    }


    for (i = 0; i < n1; i++)
    {
        array3[i] = array1[i];
    }
    for (i = n1; i < n2 + n1; i++)
    {
        array3[i] = array2[i - n1];
    }

    for (i = 0; i < n2 + n1 - 1; i++)
    {
        for (j = 0; j < n2 + n1 - i - 1; j++)
        {
            if (array3[j] > array3[j + 1])
            {
                tmp = array3[j];
                array3[j] = array3[j + 1];
                array3[j + 1] = tmp;
            }
        }
    }
    printf("\nTwo Arrays combined and sorted: ");
    for (i = 0; i < n2 + n1; i++)
    {
        printf("%d; ", array3[i]);
    }
}