#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include "function.h"
void console()
{
    rewind(stdin);// чистит поток
    getchar();//останавливает консоль
    system("cls");//чистит консоль
}

void check(int* num, int a)
{
    if (a == 1) {
        scanf_s("%d", num);
        while (getchar() != '\n' || (*num) < 1 || (*num) > 4)
        {
            rewind(stdin);
            printf("Error: please enter correct data:\n");
            scanf_s("%d", num);
        }
    }
    if (a == 2)
    {
        long long tmp;
        scanf_s("%10lld", &tmp);
        while (getchar() != '\n' || tmp != (int)tmp)
        {
            rewind(stdin);
            printf("\nErorr: please enter correct data:\n");
            scanf_s("%10lld", &tmp);
        }
        *num = tmp;
    }
    if (a == 3)
    {
        scanf_s("%d", num);
        while (getchar() != '\n' || (*num) < 1 || (*num) > 2)
        {
            rewind(stdin);
            printf("\nErorr: please enter correct data:\n");
            scanf_s("%d", num);
        }
    }
    if (a == 4)
    {
        long long tmp;
        scanf_s("%10lld", &tmp);
        while (getchar() != '\n' || tmp != (int)tmp || tmp < 1)
        {
            rewind(stdin);
            printf("\nErorr: please enter correct data:\n");
            scanf_s("%10lld", &tmp);
        }
        *num = tmp;
    }
}

void inputMas1(int* arr, int N)
{
    for (int i = 0; i < N; i++)
    {
        printf("Enter an arr element:\n");
        check(&arr[i], 2);
    }
}
void outputMas1(int* arr, int N)
{
    for (int i = 0; i < N; i++)
    {
        printf("%d ", arr[i]);
    }
}
void first()
{

    int n;
    printf("Enter the number of elements in the arr:\n");
    check(&n, 4);
    int* mass = (int*)malloc(n * sizeof(int));//выделяет память в которой есть мусор
    inputMas1(mass, n);
    int flag = 0, N = n;
    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < N; j++)
        {
            if (mass[i] == mass[j])
            {
                flag = 1;
                for (int k = j; k < N; k++)
                    mass[k] = mass[k + 1];
                mass = (int*)realloc(mass, (n - 1) * sizeof(int));//перевыделяет память(когда ее нужно изменить
                n--;
                j--;
            }
        }
    }
    if (flag == 1)
    {
        printf("\nNew arr:\n");
        outputMas1(mass, n);
    }
    else { printf("\nThere are no duplicate elements here\n"); }
}

void pamiatMassiva(int*** mas, int n, int m)
{
    (*mas) = (int**)calloc(n, sizeof(int*));//выделяет память и чистит ее(все элементы 0)
    for (int i = 0; i < n; i++)
    {
        (*mas)[i] = (int*)calloc(m, sizeof(int));
    }
}
void inputColumns(int* mas, int n, int a)
{

    if (a == 1)
    {
        for (int i = 0; i < n; i++)
        {
            *(mas + i) = (rand() % 20) - 10;
        }
    }
    if (a == 2)
    {
        for (int i = 0; i < n; i++)
        {
            printf("Enter an arr element: \n");
            check(&(*(mas + i)), 2);
        }
    }
}
void inputMas2(int** matr, int n, int m)
{
    int a;
    printf("Choose:\n1)random input\n2)custom input\n");
    check(&a, 3);

    int i, j;
    for (i = 0; i < n; i++)
        inputColumns(*(matr + i), m, a);
}
void outputColumns(int* m, int n)
{
    for (int i = 0; i < n; i++)
        printf("%d\t", *(m + i));
    printf("\n");
}
void outputMas2(int** matr, int n, int m)
{
    for (int i = 0; i < n; i++)
        outputColumns(matr[i], m);
}
void third()
{
    srand(time(NULL));
    int** mas;
    int N, M, k;
    printf("Enter amount of rows:\n");
    check(&N, 4);
    printf("Enter amount of columns:\n");
    check(&M, 4);
    pamiatMassiva(&mas, N, M);
    inputMas2(mas, N, M);
    printf("Enter amount of shifts:\n");
    check(&k, 4);
    int temp = 0;
    outputMas2(mas, N, M);
    printf("\n\n\n");
    while (k != 0) {
        for (int i = 0; i < N; i++)
        {
            temp = mas[i][0];
            for (int j = 0; j < M; j++)
            {
                if (j != M - 1)
                    mas[i][j] = mas[i][j + 1];
                else
                    mas[i][j] = temp;
            }
        }
        k--;
    }
    outputMas2(mas, N, M);
}

void inputColumns2(int** mas)
{
    int i = 1, j = 0;
    (*mas) = NULL;//очистка памяти
    do
    {
        printf("Enter an arr element (if u want to finish input row, please enter -100):\n");
        (*mas) = (int*)realloc((*mas), i * sizeof(int));
        check(&(*mas)[j], 2);
        while ((*mas)[0] == -100)
        {
            printf("Error: input number(not -100):\n");
            check(&(*mas)[0], 2);
        }
        i++; j++;
    } while ((*mas)[j - 1] != -100);

}
void inputMas3(int*** mas, int n)
{
    int i;
    for (i = 0; i < n; i++)
    {
        printf("Input %d row\n\n", i + 1);
        inputColumns2(&(*mas)[i]);
    }
}
void outputColumns2(int* m)
{
    int i = 0;
    while (*(m + i) != -100)// m + i тоже самое что m[i]
    {
        printf("%d\t", m[i]);
        i++;
    }
    printf("\n");
}
void outputMas3(int** matr, int n)
{
    for (int i = 0; i < n; i++)
        outputColumns2(matr[i]);
}
void sdvigstrok(int*** mas, int* N)
{
    int temp = (*N);
    for (int i = 0; i < (*N); i++)
    {
        if ((*mas)[i][0] == -100)
        {
            (*N)--;
            for (int k = i; k <= (*N); k++)
            {
                (*mas)[k] = (*mas)[k + 1];
            }
            (*mas) = (int**)realloc((*mas), (*N) * sizeof(int*));
            i--;
        }
    }
}
void second()
{
    int N;
    int** mas;
    printf("Input amount of rows:\n");
    check(&N, 4);
    mas = (int**)calloc(N, sizeof(int*));
    inputMas3(&mas, N);
    printf("The entered array:\n");
    outputMas3(mas, N);
    int flag = 0;
    for (int i = 0; i < N; i++)
    {
        int j = 0, amount = 0;
        while (mas[i][j] != -100)
        {
            amount++; j++;
        }
        for (j = 0; j < amount; j++)
        {
            if (mas[i][j] < 0)
            {
                flag = 1;
                for (int k = j; k < amount; k++)
                    mas[i][k] = mas[i][k + 1];
                mas[i] = (int*)realloc(mas[i], amount * sizeof(int));
                amount--;
                j--;
            }
        }

    }
    sdvigstrok(&mas, &N);
    if (N == 0)printf("All negative elements are removed: the array is empty\n");// когда пустой массив(все элементы отрицательные)
    else
    if (flag == 1)
    {
        printf("New array:\n");
        outputMas3(mas, N);
    }
    else { printf("\nThere are no negative elements here\n"); }
}

