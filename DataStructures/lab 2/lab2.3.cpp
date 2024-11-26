#include <stdio.h>
#include <stdlib.h>
int asort(int*,int);
int search(int*,int,int);
int main()
{
    int n,*arr,f,res;
    printf("how many students belong to the class? ");
    scanf("%d",&n);
    arr=(int*)malloc(n*sizeof(int));
    for (int i=0;i<n;i++)
    {
        printf("enter roll.no of student %d: ",i+1);
        scanf("%d",&arr[i]);
    }
    asort(arr,n);
    printf("roll.no of students in ascending order is: ");
    for (int i=0;i<n;i++)
    {
        printf("%d ",arr[i]);
    }
    printf("\nwhich roll.no do you wanna check? ");
    scanf("%d",&f);
    res=search(arr,n,f);
    if (res==0)
    {
        printf("the roll.no you entered is not present!");
    }
    else
    {
        printf("the roll.no is at position %d!",res);
    }
    
    
}
int asort(int* arr,int n)
{
    {
int temp;
    for (int i=0;i<n;i++)
    {
        for (int j=0;j<i;j++)
        {
            if(arr[j]>arr[i])
            {
                temp=arr[i];
                arr[i]=arr[j];
                arr[j]=temp;
            }
        }
    }
    return *arr;
}
}
int search(int* arr,int n,int f)
{
    int l,h,m;
    l=0;
    h=n-1;
    
    while (l<=h)
    {
        m=(l+h)/2;
        if (arr[m]==f)
    {
        return m+1;
    }
    else if (f>arr[m])
    {
        l=m+1;
    }
    else if (f<arr[m])
    {
        h=m-1;
    }
    }
    return 0;
    
}