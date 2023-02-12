/*============================================================================================================
FILENAME        :main.c
DESCRIPTION     :Write a program that creates a phonebook using a singly linked list.
AUTHOR          :Zach Riane I. Machacon
CREATED ON      :16 February 2022
============================================================================================================*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "sllFuncs.h"

extern int nodeCount;

int main(){

    NODE *head = NULL, *new_node;
    char choice, name[30], number[15];
    int position, choiceOfChange;
    clearScr();
    printf("Welcome to Zach Riane Machacon's Phonebook!\n\n");
    printf("Loading...\n\n");
    delay(2);
    clearScr();
    do{
        showMenu();
        printf("Choice : ");
        scanf(" %c", &choice);
        if(choice == 'a')
        {
            clearScr();
            new_node = createNode();
            if(new_node == NULL)
                continue;
            else
            {
                printf("Name : ");
                scanf(" %[^\n]s", name);
                printf("Number: ");
                scanf(" %[^\n]s", number);
                assign(&new_node, name, number);
                printf("Where would you like the new record to be inserted in?\n");
                printf("1. Front\n");
                printf("2. Rear\n");
                printf("3. Specific position\n");
                printf("Enter your choice : ");
                scanf("%d", &choiceOfChange);
                while(choiceOfChange < 0 || choiceOfChange > 3)
                {
                    printf("You have entered an invalid choice. Please try again.\n");
                    printf("Enter your choice : ");
                    scanf("%d", &choiceOfChange);
                }
                if(choiceOfChange == 1)
                    insert(new_node, &head, -1);
                else if(choiceOfChange == 2)
                    insert(new_node, &head, -2);
                else if(choiceOfChange == 3)
                {
                    showData(head);
                    printf("Enter a position to insert in : ");
                    scanf("%d", &position);
                    if(head != NULL)
                    {
                        while(position > nodeCount || position < 1)
                        {
                            printf("Invalid position. Enter a position to insert in : ");
                            scanf("%d", &position);
                        }
                    }
                    insert(new_node, &head, position);
                }
            }
        }

        else if(choice == 'b')
        {
            clearScr();
            showData(head);
            printf("Press ENTER key to continue...");
            fflush(stdin);
            getchar();
        }

        else if(choice == 'c')
        {
            clearScr();
            if(head == NULL)
                printf("\n\nERROR: No records available.\n\n");
            else
            {
                showData(head);
                printf("Record to be changed: ");
                scanf("%d", &position);
                while(position > nodeCount || position < 1)
                {
                    printf("ERROR: No record in that position. Please try again.\n");
                    printf("Record to be changed: ");
                    scanf("%d", &position);
                } 
                printf("What would you like to change?\n");
                printf("1. Name\n");
                printf("2. Phone number\n");
                printf("3. Both name and number\n");
                printf("Enter your choice : ");
                scanf("%d", &choiceOfChange);
                while(choiceOfChange < 0 || choiceOfChange > 3)
                {
                    printf("You have entered an invalid choice. Please try again.\n");
                    printf("Enter your choice : ");
                    scanf("%d", &choiceOfChange);
                }
                if(choiceOfChange == 1)
                {
                    printf("New name : ");
                    scanf(" %[^\n]s", name);
                    changeRecord(&head, position, choiceOfChange, name, number);
                }
                else if(choiceOfChange == 2)
                {
                    printf("New number: ");
                    scanf(" %[^\n]s", number);
                    changeRecord(&head, position, choiceOfChange, name, number);
                }
                else if(choiceOfChange == 3)
                {
                    printf("New name : ");
                    scanf(" %[^\n]s", name);
                    printf("New number : ");
                    scanf(" %[^\n]s", number);
                    changeRecord(&head, position, choiceOfChange, name, number);
                }
            }
        }

        else if(choice == 'd')
        {
            clearScr();
            showData(head);
            if(nodeCount > 0)
            {
                printf("Record to be removed : ");
                scanf("%d", &position);
                while(position > nodeCount || position < 1)
                {
                    printf("You have entered an invalid record. Please try again.\n");
                    printf("Record to be removed : ");
                    scanf("%d", &position);
                }
                removeRecord(&head, position);
            }
        }
    if(choice != 'e')
    {
        delay(1);
        clearScr();
    }
    else
    {
        clearScr();
        printf("Thank you! See you next time!\n\n");
        delay(1);
        clearScr();
    }
    }while(choice != 'e');
    return 0;
}