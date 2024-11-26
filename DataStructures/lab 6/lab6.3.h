//Header file (to implement stack adt using singley linked lists)
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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
   //int peek();
   //void display();
   int isempty();
   void checkbal(char*);
};


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
       //int p=top->data;
       top=top->next;
       //return p;
       return 1;
   }
}

void  stack::checkbal(char *str)
{
    if (str[0] == ')' || str[strlen(str) - 2] == '(')
            {
                printf("The parantheses are not balanced");
                return;
            }
    else
    {
        for (int i = 0; i < (strlen(str) - 1); i++)
        {
            if (str[i] == '(')
            {
                push(str[i]);
            }
            else if (str[i] == ')')
            {
                if (isempty())
                {
                    printf("The parantheses are not balanced");
                    break;
                }
                else
                {
                    pop();
                }
            }
            else
            {
                printf("Character entered not supported in this program!");
                break;
            }
        }
    }
    if (isempty())
    {
        printf("The parantheses are balanced");
    }
    else
    {
        printf("The parantheses are not balanced");
    }
}

//Method to check if stack is empty
int stack::isempty()
{
    if (top==NULL)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

// //Method to peek
// int stack::peek()
// {
//    if (top==NULL)
//    {
//        return 0;
//    }
//    else
//    {
//        return top->data;
//    }
// }

// //Method to display
// void stack::display()
// {
//    printf("\nThe elements in the stack are: ");
//    struct node *temp=top;
//    int count=0;
//    while(temp!=NULL)
//    {
//        count+=1;
//        temp=temp->next;
//    }
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
// }