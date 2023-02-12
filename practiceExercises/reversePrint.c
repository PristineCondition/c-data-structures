#include <stdio.h>
#include <stdlib.h>

void reversePrint(int *numArr, int numElements);

int main(){

    int numElements;
    printf("Enter number of elements: ");
    scanf("%d", &numElements);
    int *numArr = (int *) malloc(sizeof(int) * numElements);
    for(int i = 0; i < numElements; i++)
    {
        printf("Enter number #%d: ", i+1);
        scanf("%d", numArr+i);
    }
    reversePrint(numArr, numElements);

    return 0;
}

void reversePrint(int *numArr, int numElements){

    for(int i = numElements-1; i >= 0; i--)
        printf("%d ", *(numArr+i));
}