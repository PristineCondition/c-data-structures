#ifndef DLLFUNCS_H
#define DLLFUNCS_H

typedef struct node{
    char name[30];
    char phone[15];
    struct node *next, *prev;
}NODE;

void showMenu();
NODE *createNode();
void assign(NODE **new, char person[], char number[]);
void insert(NODE *new, NODE **L, int position);
void removeRecord(NODE **L, int position);
void changeRecord(NODE **L, int position, int choice, char person[], char number[]);
void showData(NODE *L);
void showDataReverse(NODE **L);
void clearScr();
void delay(int seconds);
void pause();

#endif