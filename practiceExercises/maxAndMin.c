#include <stdio.h>
#include <stdlib.h>

void maxAndMin(int *numArr, int numElements);

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
    maxAndMin(numArr, numElements);
    return 0;
}

void maxAndMin(int *numArr, int numElements){

    int max, min, i, j, temp;
    for(i = 0; i < numElements; i++)
    {
        for(j = i+1; j < numElements; j++)
        {
            if(*(numArr+i) > *(numArr+j))
            {
                temp = *(numArr+i); 
                *(numArr+i) = *(numArr+j); 
                *(numArr+j) = temp; 
            }
        }
    }
    printf("Min: %d\n", *numArr);
    printf("Max: %d", *(numArr+numElements-1));
}