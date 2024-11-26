#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "lab6.3.h"

int main()
{
    char str[100];
    stack s1;
    int n;
    while (1)
    {
        printf("\n\nEnter\n1. Check Balance\n2. Exit: ");
        scanf("%d", &n);
        getchar();
        switch (n)
        {
        case 1:
            printf("\nEnter a string of paranthesis [insclusive of '(' or ')' ]: ");
            fgets(str, 100, stdin);
            s1.checkbal(str);
            break;

        case 2:
            printf("Programn is terminated");
            exit(0);
        }
    }
}
