//Array implementation of List ADT
#include<stdio.h>
#include<stdlib.h>
#define SIZE 5
class List
{
   int arr[SIZE];
   int cur;
   public:
       List()
       {
           cur = -1;
       }
       int insbeg(int);
       void display();
       int append(int);
       int inspos(int,int);
       void search(int);
       int delbegin();
       int pop();
       int delpos(int);
       
};

int main()
{
   List l1;
   int choice, num, pos;
   while (1)
   {
    //    getchar();
    //    getchar();
    //    system("clear");
       printf("\nEnter \n1. Insert Begin\n2. Insert End\n3. Insert Position");
       printf("\n4. Delete Begin\n5. Delete End\n6. Delete Position");
       printf("\n7. Search\n8. Display\n9. Exit");
       printf("\n Enter a choice:");
       scanf("%d",&choice);
       switch (choice)
       {
       case 1:
           printf("\n Enter the number insert: ");
           scanf("%d",&num);
           if(l1.insbeg(num))
           {
               printf("\n %d successfully inserted.",num);
           }
           else
           {
               printf("\n Failed to insert %d. The list is full.",num);
           }
           break;
           
       case 2:
           printf("\nEnter the number to append: ");
           scanf("%d",&num);
           if (l1.append(num))
           {
               printf("\n %d is successfully appended.",num);
           }
           else
           {
               printf("\nFailed to append %d. The list is full",num);
           }
           break;
           
       case 3:
           printf("\nEnter the position where you want to insert: ");
           scanf("%d",&pos);
           printf("\nEnter the number you want to insert: ");
           scanf("%d",&num);
           if (l1.inspos(pos,num))
           {
               printf("%d is successfully appended at position %d ",num,pos);
           }
           else
           {
               printf("Insertion of %d at position %dfailed",num,pos);
           }
           break;
           
       case 4:
           if (l1.delbegin())
           {
               printf("\nThe beginning number has been deleted successfully.");
           }
           else
           {
               printf("\nDeletion of the beginning number failed.");
           }
           break;
           
       case 5:
           if (l1.pop())
           {
               printf("\nLast number deleted successfully.");
           }
           else
           {
               printf("\nDeletion of last number failed.");
           }
           break;
       case 6:
           printf("\nEnter the number's position you want to delete: ");
           scanf("%d",&pos);
           if (l1.delpos(pos))
           {
               printf("\nThe number in position %d has been deleted.",pos);
           }
           else
           {
               printf("\nDeletion of number at position %d failed.",pos);
           }
           break;
       case 7:
           printf("\nEnter the number you want to search: ");
           scanf("%d",&num);
           l1.search(num);
           break;
           
       case 8:
           l1.display();
           break;
           
       case 9:
           exit(0);
           break;
       default:
           printf("\n Enter a valid choice\n");
           break;
       }

   }
   return 0;
}

//Method to insert a number in begining of the list
int List::insbeg(int num)
{
   if(cur==SIZE-1)
   {
       return 0;
   }
   else if(cur==-1)
   {
       cur = 0;
       arr[0]=num;
       return 1;
   }
   else
   {
       for(int i=cur;i>=0;i--)
       {
           arr[i+1]=arr[i];
       }
       cur = cur + 1;
       arr[0]=num;
       return 1;

   }
}
//Method to display the contents of the list
void List::display()
{
   printf("\nThe contents of the list are:");
   for(int i=0;i<=cur;i++)
   {
       printf("%d ",arr[i]);
   }
}
//Method to append an element to the array
int List::append(int num)
{
   if (cur==(SIZE-1))
   {
       return 0;
   }
   else
   {
       cur = cur+1;
       arr[cur]=num;
       return 1;
   }
}
//Method to insert positon and insert an element
int List::inspos(int pos,int num)
{
   if (cur==(SIZE-1))
   {
       return 0;
   }
   else if(pos>cur+2)
   {
       return 0;
   }
   else if(cur==-1)
   {
       cur = 0;
       arr[0]=num;
       return 1;
   }
   else
   {
       for (int i=cur;i>pos-1;i--)
       {
           arr[i+1]=arr[i];
       }
       cur=cur+1;
       arr[pos-1]=num;
       return 1;
   }
}
//method to search a number
void List::search(int num)
{
    int flag;
    for (int i=cur;i>=0;i--)
    {
        if (num==arr[i])
        {
            flag=i+1;
            break;
        }
        else
        {
            flag=0;
        }
    }
    if (flag==0)
    {
        printf("\nThe number entered is not found");
    }
    else
    {
        printf("The entered number is found at position %d",flag);
    }
}
//method to delete the element in the first position
int List::delbegin()
{
    if(cur==-1)
    {
        return 0;
    }
    else
    {
        for(int i=0;i<=cur;i++)
        {
            arr[i]=arr[i+1];
        }
        cur=cur-1;
    }
}
//method to pop
int List::pop()
{
    if (cur==-1)
    {
        return 0;
    }
    else
    {
        cur=cur-1;
        return 1;
    }
}
int List::delpos(int pos)
{
    if (cur==-1)
    {
        return 0;
    }
    else if (pos>cur+1)
    {
        return 0;
    }
    else
    {
        for (int i=(pos-1);i<cur;i++)
        {
            arr[i]=arr[i+1];
        }
        cur=cur-1;
        return 1;
    }
    
}
