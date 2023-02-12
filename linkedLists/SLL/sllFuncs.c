#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "sllFuncs.h"

int nodeCount = 0;

void showMenu(){

    printf("Menu:\n");
    printf("[a]ppend\n");
    printf("[b]rowse\n");
    printf("[c]hange\n");
    printf("[d]elete\n");
    printf("[e]xit\n");
}

NODE *createNode(){

    NODE *new = malloc(sizeof(NODE));
    if(new == NULL)
        printf("ERROR: Not enough memory on this device to create a new contact!\n");
    return new;
}

void assign(NODE **new, char person[], char number[]){

    strcpy((*new)->name, person);
    strcpy((*new)->phone, number);
}

void insert(NODE *new, NODE **L, int position){

    int currentPos = 0;
    if(position == -1 || *L == NULL || position == 1)
    {
        new->next = *L;
        *L = new;
        printf("\n\nSUCCESS: New record added to the front!\n\n");
        nodeCount++;
    }
    else if(position == -2)
    {
        NODE *current_node = malloc(sizeof(NODE));
        if(current_node == NULL)
            printf("ERROR: Not enough memory on this device to create a new contact!\n");
        else
        {
            current_node = *L;
            while(current_node->next != NULL)
                current_node = current_node->next;
            new->next = current_node->next;
            current_node->next = new;
            printf("\n\nSUCCESS: New record added to the rear!\n\n");
            nodeCount++;
        }
    }
    else if(position > 1)
    {
        position--;
        NODE *current_node = malloc(sizeof(NODE)), *prev_node;
        if(current_node == NULL)
            printf("ERROR: Not enough memory on this device to create a new contact!\n");
        else
        {
            current_node = *L;
            do{
                prev_node = current_node;
                current_node = current_node->next;
                currentPos++;
            }while(currentPos < position);
            new->next = prev_node->next;
            prev_node->next = new;
            printf("\n\nSUCCESS: New record added to the position #%d!\n\n", position+1);
            nodeCount++;
        }
    }
}

void changeRecord(NODE **L, int position, int choice, char person[], char number[]){

    position--;
    int currentPos = 0;
    NODE *current_node = malloc(sizeof(NODE));
    if(current_node == NULL)
        printf("ERROR: Not enough memory on this device to carry out this operation!\n");
    else
    {
        current_node = *L;
        if(position > 0)
        {
            do{
                current_node = current_node->next;
                currentPos++;
            }while(currentPos < position);
        }
        if(current_node == NULL)
        {
            printf("\n\nERROR: No record located.\n");
            return;
        }
        if(choice == 1)
        {
            strcpy(current_node->name, person);
            printf("\n\nSUCCESS: Name change successful!\n\n");
        }    
        else if(choice == 2)
        {
            strcpy(current_node->phone, number);
            printf("\n\nSUCCESS: Number change successful!\n\n");
        } 
        else if(choice == 3)
        {
            strcpy(current_node->name, person);
            strcpy(current_node->phone, number);
            printf("\n\nSUCCESS: Record change successful!\n\n");
        }
    }
}

void removeRecord(NODE **L, int position){

    position--;
    int currentPos = 0;
    NODE *current_node = malloc(sizeof(NODE)), *prev_node;
    if(current_node == NULL)
        printf("ERROR: Not enough memory on this device to carry out this operation!\n");
    else
    {
        current_node = *L;
        if(position == 0)
        {
            *L = current_node->next;
            free(current_node);
            printf("\n\nSUCCESS: Delete successful!\n\n");
            nodeCount--;
        }
        if(position > 0)
        {
            do{
                prev_node = current_node;
                current_node = current_node->next;
                currentPos++;
            }while(currentPos < position);
            prev_node->next = current_node->next;
            free(current_node);
            printf("\n\nSUCCESS: Delete successful!\n\n");
            nodeCount--;
        }
        else if(current_node == NULL)
            printf("\n\nERROR: No record located.\n");
    }
}

void showData(NODE *L){

    int i = 1;
    if(L == NULL)
        printf("\n\nERROR: No records available.\n\n");
    else
    {
        printf("\n\nPhonebook\n\n");
        if(nodeCount == 1)
            printf("%d contact available\n\n", nodeCount);
        else
            printf("%d contacts available\n\n", nodeCount);
        while(L != NULL)
        {
            printf("%d. %-35s\t\t\t%s\n", i, L->name, L->phone);
            i++;
            L = L->next;
        }
        printf("\n");
    }
}

void clearScr(){
    printf("\e[1;1H\e[2J");
}

void delay(int seconds)
{
    int milli_seconds = 1000 * seconds;
    clock_t start_time = clock();
    while (clock() < start_time + milli_seconds);
}

void pause(){
    #ifdef _WIN32
        delay(2);
    #elif __APPLE__
        delay(2000);
    #elif __unix__
        delay(2000);
    #endif
}