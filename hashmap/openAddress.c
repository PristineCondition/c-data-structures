#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <math.h>
#define MAX 20

int numHash[MAX + 1] = { };

void printMenu(){

    printf("[1] Add records\n");
    printf("[2] Delete records\n");
    printf("[3] Show records\n");
    printf("[4] Search records\n");
    printf("[5] Exit\n");
}

bool searchNum(int num){

    int index = (num % 10 != 0 ) ? num % 10 : num, foundFlag = 0;
    if(numHash[index] == num) return true;
    else
    {
        for(;index < MAX + 1; index++)
        {
            if(numHash[index] == num)
                return true;
        }
        return false;
    }
}

void insert(int num){

    // Attempt to insert at index; if index is taken, insert at next slot.
    int index = (num % 10 != 0 ) ? num % 10 : num;
    if(numHash[index] == 0)
        numHash[index] = num;
    else
    {
        for(; numHash[index] != 0 && index < MAX + 1; index++){}
        numHash[index] = num;
    }
}

void delete(int num){

    int index = (num % 10 != 0 ) ? num % 10 : num;
    if(numHash[index] == num)
        numHash[index] = 0;
    else
    {
        for(; numHash[index] != num && index < MAX + 1; index++){}
        numHash[index] = 0;
    }  
}

void printHash(){

    int i;
    for(i = 1; i < MAX + 1; i++)
        printf("%d ", numHash[i]);
    printf("\n");    
}


int main(){

    int choice;
    do{
        printMenu();
        printf("Enter choice: ");
        scanf("%d", &choice);
        int numOfNodes, num, i, numToSearch, numToDelete;
        if(choice == 1)
        {
            printf("How many numbers do you want in the hash table? ");
            scanf("%d", &numOfNodes);
            for(i = 0; i < numOfNodes; i++)
            {
                printf("Enter number #%d: ", i+1);
                scanf("%d", &num);
                insert(num);
            }
        }

        if(choice == 2)
        {
            printf("How many numbers would you like to delete? ");
            scanf("%d", &numToDelete);
            for(i = 0; i < numToDelete; i++)
            {
                printf("Enter number #%d: ", i+1);
                scanf("%d", &num);
                delete(num);
            }
        }

        if(choice == 3)
            printHash();

        if(choice == 4)
        {
            printf("How many numbers would you like to search? ");
            scanf("%d", &numToSearch);
            for(i = 0; i < numToSearch; i++)
            {
                printf("Enter number #%d: ", i+1);
                scanf("%d", &num);
                printf("%d (%d)\n", num, searchNum(num));
            }
        }

    }while(choice < 5 && choice >= 1);
    return 0;
}