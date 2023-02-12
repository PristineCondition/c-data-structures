#include <stdio.h>
#include <stdlib.h>

void printAlpha(char *alpha);

int main(){

    char *alpha = malloc(sizeof(char));
    *alpha = 'A';
    printAlpha(alpha);

    return 0;
}

void printAlpha(char *alpha){

    while(*alpha <= 'Z')
    {
        printf("%c ", *alpha);
        (*alpha)++;
    }
}