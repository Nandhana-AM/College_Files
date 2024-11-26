//Implementaion of stack ADT using array

#include <stdio.h>
#include <stdlib.h>
#define size 5

class stack
{
   int arr[size];
   int top;
   public:
   stack()
   {
       top=-1;
   }
   int push(char);
   char pop();
   char peek();
   void display();
};

int main()
{
   char num,p;
   int n;
   stack a1;
   while(1)
   {
       printf("\nEnter\n1. To push an element\n2. To pop an element\n3. To peek\n4. Display\n5. Exit: ");
       scanf("%d",&n);
       switch(n)
   {
       case 1: 
       printf("Enter the element you want to push: ");
       scanf(" %c",&num);
       if (a1.push(num))
       {
           printf("\n%c is successfully pushed into the stack",num);
       }
       else
       {
           printf("\nThe stack is full");
       }
       break;

       case 2:
       if (p=a1.pop())
       {
           printf("\nThe top element %c is popped",p);
       }
       else
       {
           printf("\nThe stack is empty");
       }
       break;

       case 3:
       int n;
       if (p=a1.peek())
       {
           printf("\nThe top element is %c",p);
       }
       else
       {
           printf("\nThe stack is empty");
       }
       break;

       case 4:
       a1.display();
       break;

       case 5:
       printf("\nThe program is terminated");
       exit(0);
       break;
   }
   }
}
   
//Method to push an element into the stack
int stack::push(char num)
{
   if(top==size-1)
   {
       return 0;
   }
   else
   {
       top = top+1;
       arr[top]=num;
       return 1;
   }
}

//Method to pop an element from the stack
char stack::pop()
{
   if (top==-1)
   {
       return 0;
   }
   else
   {
       char p=arr[top];
       top=top-1;
       return p;
   }

}

//Method to peek at the top value 
char stack::peek()
{
   if (top==-1)
   {
       return 0;
   }
   else
   {
       return arr[top];
   }
}

//Method to display the stack
void stack::display()
{
   if (top==-1)
   {
       printf("\nThe stack is empty");
   }
   else
   {
       for (int i=0;i<=top;i++)
       {
           printf("%c ",arr[i]);
       }
   }
}