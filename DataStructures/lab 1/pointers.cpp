#include <stdio.h>
#include <stdlib.h>
int main()
{
    int* ptr;int* sum;
    ptr=(int*)malloc(sizeof(int));
    sum=(int*)malloc(sizeof(int));
    printf("enter the number: ");
    scanf("%d",ptr);
    int* i;
    i=(int*)malloc(sizeof(int));
    for ( (*i)=1;(*i)<=(*ptr);(*i)++)
    {
        (*sum)+=(*i);
    }
    printf("the sum of the integers is %d",*sum);
}