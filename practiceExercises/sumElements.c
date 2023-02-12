#include <stdio.h>
#include <stdlib.h>

int sumElements(int *numArr, int numElements);

int main(){

    int numElements, sum;
    printf("Enter number of elements: ");
    scanf("%d", &numElements);
    int *numArr = (int *) malloc(sizeof(int) * numElements);
    for(int i = 0; i < numElements; i++)
    {
        printf("Enter number #%d: ", i+1);
        scanf("%d", numArr+i);
    }
    sum = sumElements(numArr, numElements);
    printf("The sum is: %d", sum);
    return 0;
}

int sumElements(int *numArr, int numElements){

    int i, sum = 0;
    for(i = 0; i < numElements; i++)
        sum+=*(numArr+i);
    return sum;
}