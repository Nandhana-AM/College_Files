//Method to implement menu-driven program to implement infix to postfix and postfix evaluation.
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "lab6.2rough.h"

int main()
{
    int n;
    char exp[100];
    char * ptr = &exp[0];
    char postfix[strlen(exp)];
    char *ptr2=&postfix[0];
    stack s1,s2;
    printf("Enter\n1. Get Infix\n2. Convert Infix\n3. Evaluate Postfix \n4. Exit\n");
    scanf("%d",&n);
    getchar();// to consume input buffer after scanf (\n)
    switch(n)
    {
        case 1:
        printf("\nEnter the infix expression: ");
        //fgets(exp,100,stdin);
        scanf("%s",exp);
        //printf("The entered expression is %s",exp);
        // break;

        case 2:
        //printf("code is here");
        //ptr=
        ptr2=s1.convert(ptr,postfix);
        //printf("code is here");
        for (int i = 0; i < strlen(exp); i++) 
            printf("%c", *(ptr2 + i));
        //break;

        case 3:
        s2.evaluate(ptr2);
    }
}