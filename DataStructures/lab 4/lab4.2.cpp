//Method to insert elements in ascending in linked list and merge two of them
#include <stdio.h>
#include <stdlib.h>
#include "lab4.2.head.h"

int main()
{
    int num,n;
    class list l1,l2,l3;
    while(1)
    {
        printf("\nEnter\n1. Insert in list 1\n2. Insert in list 2\n3. Merge list 1 and list 2 into list 3\n4. Display\n5. Exit: ");
        scanf("%d",&n);
        switch (n)
        {
            case 1:
            printf("\nEnter the number you want to insert in list 1: ");
            scanf("%d",&num);
            if (l1.insert(num))
            {
                printf("\nInsertion in list 1 successful.");
            }
            else
            {
                printf("\nInsertion in list 1 failed.");
            }
            break;
            
            case 2:
            printf("\nEnter the number you want to insert in list 2: ");
            scanf("%d",&num);
            if (l2.insert(num))
            {
                printf("\nInsertion in list 2 successful.");
            }
            else
            {
                printf("\nInsertion in list 2 failed.");
            }
            break;
            
            case 3:
            printf("\nLists list 1 and list 2 have been merged into list 3.");
            l3.merge(l1,l2);
            break;
            
            case 4:
            printf("\nEnter\n1. To display list 1\n2. To display list 2\n3. To display list 3: ");
            int a;
            scanf("%d",&a);
            if (a==1)
            {
                printf("\nThe numbers in the list 1 are: ");
                l1.display();
                break;
            }
            else if (a==2)
            {
                printf("\nThe numbers in list 2 are: ");
                l2.display();
                break;
            }
            else if(a==3)
            {
                printf("\nThe numbers in list 3 are: ");
                l3.display();
                break;
            }

            case 5:
            printf("\nThe program is terminated.");
            exit(0);
            break;
            
        }
    }
}