#include <stdio.h>
#include "head.h"

int main()

{
    int a,b;
    int n=1;
    while (n!=6)
    {
   
    printf("\nenter:\n1 to set values\n2 to add\n3 to subtract\n4 to multiply\n5 to divide\n6 to exit\n");
    scanf("%d",&n);
    switch (n)
    {
        case 1:
        printf("\nenter the two numbers: ");
        scanf("%d%d",&a,&b);
        break;
       
        case 2:
        printf("%d",sum(a,b));
        break;
       
        case 3:
        printf("%d",diff(a,b));
        break;
       
        case 4:
        printf("%d",prod(a,b));
        break;
       
        case 5:
        printf("%f",div(a,b));
        break;
       
        case 6:
        printf("program terminated");
        break;
       
    }
   
    }
    return 0;
}