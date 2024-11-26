//Program to implement stack adt using singley linked lists
#include <stdio.h>
#include <stdlib.h>

class stack
{
   struct node
   {
       int data;
       struct node* next;
   };

   public:
   struct node* top;
   stack()
   {
       top=NULL;
   }
   int push(int);
   int pop();
   int peek();
   void display();

};

int main()
{
   int num,p,n;
   stack a1;
   while(1)
   {
       printf("\n\nEnter\n1. To push an element\n2. To pop an element\n3. To peek\n4. Display\n5. Exit: ");
       scanf("%d",&n);
       switch(n)
   {
       case 1: 
       printf("\nEnter the element you want to push: ");
       scanf(" %d",&num);
       if (a1.push(num))
       {
           printf("%d is successfully pushed into the stack",num);
       }
       else
       {
           printf("The stack is full");
       }
       break;

       case 2:
       if (p=a1.pop())
       {
           printf("\nThe top element %d is popped",p);
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
           printf("\nThe top element is %d",p);
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
int stack::push(int num)
{
   struct node* newnode;
   newnode=(struct node*)malloc(sizeof(struct node));
   if (top==NULL)
   {
       newnode->data=num;
       newnode->next=NULL;
       top=newnode;
       return 1;
   }
   else
   {
       newnode->data=num;
       newnode->next=top;
       top=newnode;
       return 1;
   }
}

//Method to pop an element from the stack
int stack::pop()
{
   if (top==NULL)
   {
       return 0;
   }
   else
   {
       int p=top->data;
       top=top->next;
       return p;
   }
}

//Method to peek
int stack::peek()
{
   if (top==NULL)
   {
       return 0;
   }
   else
   {
       return top->data;
   }
}

//Method to display the stack
void stack::display()
{
   printf("\nThe elements in the stack are: ");
   struct node *temp=top;
   int count=0;
   while(temp!=NULL)
   {
        printf("%d ",temp->data);
    //    count+=1;
       temp=temp->next;
   }
//    int arr[count];
//    temp=top;
//    for (int i=0;i<count;i++)
//    {
//        arr[i]=temp->data;
//        temp=temp->next;
//    }
//    for (int i=(count-1);i>=0;i--)
//    {
//        printf("%d ",arr[i]);
//    }
}