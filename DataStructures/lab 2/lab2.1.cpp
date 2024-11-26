#include <stdio.h>
#include <stdlib.h>
int main()
{
int n,i,f,*a,c=0;
printf("how many elements do you want in the array? ");
scanf("%d",&n);
a=(int*)malloc(n*sizeof(int));
for (i=0;i<n;i++)
{ 
    printf("enter element %d: ",i+1);
    scanf("%d",&a[i]);
}
printf("which element do you want to search: ");
scanf("%d",&f);
for (i=0;i<n;i++)
{
    if (f==a[i])
    c++;
}
if (c>0)
printf("the element is present in the array!!");
else
printf("the element is not present in the array.");
}