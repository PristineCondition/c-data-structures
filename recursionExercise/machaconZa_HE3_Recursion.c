#include <stdio.h>
#include "machaconZa_HE3_Recursion.h"

int main(){

    int n, result, i;
    printf("Enter a value of n: ");
    scanf("%d", &n);
    factorialIterative(n);
    printf("Factorial series using recursive function.\n\t");
    for(i = 1; i <= n; i++)
    {
        result = factorialRecur(i);
        printf("%d ", result);
    }
    printf("\n");
    fibonacciIterative(n);
    printf("Fibonacci series using recursive function.\n\t");
    for(i = 1; i <= n; i++)
    {
        result = fibonacciRecur(i);
        printf("%d ", result);
    }
    printf("\n");
    sumIterative(n);
    printf("Sum series using recursive function.\n\t");
    for(i = 1; i <= n; i++)
    {
        result = sumRecur(i);
        printf("%d ", result);
    }
    printf("\n");
    return 0;
}