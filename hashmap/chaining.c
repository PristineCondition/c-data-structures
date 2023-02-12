#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <math.h>
#define MAX 10

typedef struct node{
    int value;
    struct node *next;
}LL;

LL *numHash[MAX + 1];
int dupeFlag = 0;

void printMenu(){

    printf("[1] Add records\n");
    printf("[2] Delete records\n");
    printf("[3] Show records\n");
    printf("[4] Search records\n");
    printf("[5] Exit\n");
}

bool searchNum(int num){

    int index = (num % 10 == 0) ? 10 :  num % 10;
    LL *trav = numHash[index];
    for(; trav != NULL; trav = trav->next)
    {
        if(trav->value == num)
            return true;
    }
    return false;
}

bool checkDupe(int currentKey, int num){

    if(currentKey == num)
    {
        dupeFlag = 1;
        return true;
    }
    return false;
}

void insert(int num){

    // Find initial index by modulo 10
    int index = (num % 10 == 0) ? 10 :  num % 10; 
    dupeFlag = 0;
    LL *new = malloc(sizeof(LL)), *trav = numHash[index], *prev = trav;
    new->value = num;
    if(numHash[index] == NULL)
    {
        numHash[index] = malloc(sizeof(LL));
        new->next = NULL;
        numHash[index] = new;
        return;
    }
    for(; trav != NULL && checkDupe(trav->value, num) == 0; trav = trav->next)
        prev = trav;
    if(dupeFlag == 1)
    {
        printf("Number already on record!\n");
        return;
    }
    new->next = NULL;
    prev->next = new;
}

void delete(int num){

    int index = (num % 10 == 0) ? 10 :  num % 10;
    if(numHash[index] == NULL)
        return;
    LL *trav = numHash[index], *prev_node;
    if(numHash[index]->value == num)
    {
        numHash[index] = numHash[index]->next;
        free(trav);
    }
    else
    {
        for(; trav != NULL && trav->value != num ; trav = trav->next)
            prev_node = trav;
        prev_node->next = trav->next;
        free(trav);
    }
}

void printHash(){

    for(int i = 0; i <= MAX; i++)
    {
        LL *trav = numHash[i];
        if(numHash[i] != NULL)
        {
            for(; trav != NULL; trav = trav->next)
                printf("%d -> ", trav->value);
        }
        printf("\n");
    }
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