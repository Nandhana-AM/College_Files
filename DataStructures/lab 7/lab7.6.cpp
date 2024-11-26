//Program to implement queue adt using circular linked lists
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "lab7.6.h"

int main()
{
    int n;
    char str[100];
    char* ptr=&str[0];
    queue q1,q2;
    while(1)
    {
        printf("\n\nEnter\n1. String\n2. Process\n3. Exit: ");
        scanf("%d",&n);
        switch(n)
    {
        case 1: 
        printf("Enter a string with '+'s : ");
        scanf("%s",str);
        q1.string(ptr);
        printf("\nString taken as input");
        break;

        case 2:
        q1.process();
        break;

        case 3:
        printf("\nThe program is terminated");
        exit(0);
        break;
    }
    }
}