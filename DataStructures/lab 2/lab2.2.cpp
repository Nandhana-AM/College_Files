#include <stdio.h>
#include <stdlib.h>
void ascending(int*,int);
void descending(int*,int);
int main()

{
    int n,*a,ch;
    printf("how many elements do you want in the array? ");
    scanf("%d",&n);
    a=(int*)malloc(n*sizeof(int));
    for (int i=0;i<n;i++)
{ 
    printf("enter element %d: ",i+1);
    scanf("%d",&a[i]);
}
    printf("if you want to sort in ascending order, enter 1\nif you want to sort in descending order,enter 2: ");
    scanf("%d",&ch);
    switch (ch)
    {
        case 1:
        ascending(a,n);
        break;
        
        case 2:
        descending(a,n);
        break;
    }
}
void ascending(int* a, int n)
{
int temp;
    for (int i=0;i<n;i++)
    {
        for (int j=0;j<i;j++)
        {
            if(a[j]>a[i])
            {
                temp=a[i];
                a[i]=a[j];
                a[j]=temp;
            }
        }
    }
    printf("the array in ascending order is: ");
    for (int i=0;i<n;i++)
{ 
    printf("%d ",a[i]);
    
}
}
void descending(int* a, int n)
{
int temp;
    for (int i=0;i<n;i++)
    {
        for (int j=0;j<i;j++)
        {
            if(a[j]<a[i])
            {
                temp=a[i];
                a[i]=a[j];
                a[j]=temp;
            }
        }
    }
    printf("the array in descending order is: ");
    for (int i=0;i<n;i++)
{ 
    printf("%d ",a[i]);
    
}
}