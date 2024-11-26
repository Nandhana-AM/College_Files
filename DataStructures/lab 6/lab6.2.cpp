//Method to convert an infix expression to postfix expression and evaluate it
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "lab6.2.h"

int main()
{
    int n;
    char exp[100];
    char * ptr = &exp[0];
    char postfix[strlen(exp)];
    char *ptr2=&postfix[0];
    stack s1,s2;
    while(1)
    {
        printf("\nEnter\n1. Get Infix\n2. Convert Infix\n3. Evaluate Postfix \n4. Exit\n");
        scanf("%d",&n);
        getchar();// to consume input buffer after scanf (\n)
        switch(n)
    {
        case 1:
        printf("\nEnter the infix expression: ");
        scanf("%s",exp);
        break;

        case 2:
        ptr2=s1.convert(ptr,postfix);
        for (int i = 0; i < strlen(exp); i++) 
            printf("%c", *(ptr2 + i));
        break;

        case 3:
        s2.evaluate(ptr2);
        break;

        case 4:
        printf("\nThe program is terminated.");
        exit(0);
        break;
    }
    }
}