#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void checkDuck(char *num);

int main(){

    char *num;
    num = (char*) malloc(40*sizeof(char));
    printf("Enter a number: ");
    scanf("%s", num);
    checkDuck(num);
    return 0;
}

void checkDuck(char *num){

    if(num[0] == '-')
        printf("%s is not a duck number.", num);
    else
    {
        int i = 0, length = strlen(num), flag = 0;
        while(i < length && num[i] == '0')
            i++;
        while(i < length && flag == 0)
        {
            if(num[i] == '0')
                flag = 1;
            i++;
        }
        if(flag == 1)
            printf("%s is a duck number.", num);
        else
            printf("%s is not a duck number.", num);
    }
}