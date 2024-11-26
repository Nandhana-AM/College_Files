//Program to implement round robin's schedule using circular linked lists
#include <stdio.h>
#include <stdlib.h>
#include "lab7.5.h"

int main()
{
    int num,p;
    int n;
    queue q1;
    while(1)
    {
        printf("\n\nEnter\n1. Insert process\n2. Execute\n3. Exit: ");
        scanf("%d",&n);
        switch(n)
    {
        case 1: 
        printf("Enter the time required to complete this process: ");
        scanf("%d",&num);
        if (q1.enq(num))
        {
            printf("\n%d is successfully added to the queue",num);
        }
        else
        {
            printf("\nThe queue is full");
        }
        break;

        case 2:
        p=q1.deq();
        if (p==1)
        {
            printf("\nThe process has been executed");
        }
        else if (p==2)
        {
            printf("\nThe process hasn't been completely executed");
        }
        else if (p==3)
        {
            printf("\nNo process to execute");
        }
        break;

        case 3:
        printf("\nThe program is terminated");
        exit(0);
        break;
    }
    }
}