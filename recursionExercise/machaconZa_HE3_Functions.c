#include <stdio.h>
#include "machaconZa_HE3_Recursion.h"

void factorialIterative(int n){

    int product = 1, i;
    printf("Factorial series using non-recursive function.\n\t");
    for(i = 1; i <= n; i++)
    {
        product*=i;
        printf("%d ", product);
    }
    printf("\n");
}

int factorialRecur(int n){

    if(n > 0)
        return n*factorialRecur(n-1);
    return 1;
}

void fibonacciIterative(int n){

    int i, a, b, sum;
    printf("Fibonacci series using non-recursive function.\n\t");
    for(i = 0; i < n; i++)
    {
        a = (i == 1) ? 0 : b;
        b = (i == 1) ? 1 : sum;
        sum = (i == 0) ? 1 : a+b;
        printf("%d ", sum);
    }
    printf("\n");
}

int fibonacciRecur(int n){

    if(n <= 1)
        return n;
    return fibonacciRecur(n - 1) + fibonacciRecur(n - 2);
}

void sumIterative(int n){

    int i, sum = 0;
    printf("Sum series using non-recursive function.\n\t");
    for(i = 1; i <= n; i++)
    {
        sum+=i;
        printf("%d ", sum);
    }
    printf("\n");
}

int sumRecur(int n){

    if(n > 0)
        return n + sumRecur(n-1);
    return 0;
}