//Method to implement a browser's front and back functionality
#include <stdio.h>
#include <stdlib.h>
#include "lab5.2head.h"

int main()
{
    int n;
    webpage w1;
    while (1)
    {
        printf("\nEnter\n1. New webpage\n2. Front\n3. Back\n4. Exit\n5. Current webpage: ");
        scanf("%d",&n);
        switch (n)
        {
            case 1:
            printf("\nEnter the data(integer) you want to store in the webpage: ");
            int dat;
            scanf("%d",&dat);
            if (w1.openwebpage(dat))
            {
                printf("\nWebpage opened successfully.");
            }
            else
            {
                printf("\nCould not open webpage.");
            }
            break;

            case 2:
            if (w1.front())
            {
                printf("\nSuccessfully moved to the next webpage.");
            }
            else
            {
                printf("\nFailed to move to the next webpage.");
            }
            break;

            case 3:
            if (w1.back())
            {
                printf("\nSuccessfully moved to the previous webpage.");
            }
            else
            {
                printf("\nFailed to move to the previous webpage.");
            }
            break;

            case 4:
            printf("\nThe program is terminated.");
            exit(0);
            break;

            case 5:
            w1.currentwebpage();
            break;
        }
    }
}