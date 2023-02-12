#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <math.h>
#define MAX 1000

int numHash[MAX + 1][2];

bool searchNum(int x){

    if(numHash[x][0] == 1 && x >= 0) return true;
    else if(numHash[abs(x)][1] == 1) return true;
    else return false;
}

void insert(int numArr[], int sizeOfArr){

    int i;
    for(i = 0; i < sizeOfArr; i++)
    {
        if(numArr[i] >= 0)
            numHash[numArr[i]][0] = 1;
        else
            numHash[abs(numArr[i])][1] = 1;
    }
}

int main(){

    int numOfNodes, num, i, numToSearch;
    printf("How many numbers do you want in the hash table? ");
    scanf("%d", &numOfNodes);
    int *numArr = (int *) malloc(numOfNodes * sizeof(int));
    for(i = 0; i < numOfNodes; i++)
    {
        printf("Enter number #%d: ", i+1);
        scanf("%d", &num);
        numArr[i] = num;
    }
    insert(numArr, numOfNodes);
    printf("How many numbers would you like to search? ");
    scanf("%d", &numToSearch);
    for(i = 0; i < numToSearch; i++)
    {
        printf("Enter number #%d: ", i+1);
        scanf("%d", &num);
        printf("%d (%d)\n", num, searchNum(num));
    }
    return 0;
}