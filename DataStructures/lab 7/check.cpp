#include <stdio.h>
#include<stdlib.h>
#define fix 20
//menu driven program to implement a queue using linked list

class queue
{
struct node 
  {
      int data;
      struct node* next; 
  };
  struct node* head;
  struct node* tail;
  public:
  queue()
  {
    head=NULL;
    tail=NULL;
  }

  int enqueue(int);
  int dequeue();
  void peek();
  void display();
};
int main()
{
   queue l1;
   int choice,num,x,value;
   while(1)
   {
   printf("\n Enter the choice \n 1. Insert Process \n 2. Execute \n 3. Exit\n");
   scanf("\n%d",&choice);
   switch(choice)
       {
       case 1:
       printf("\nenter the number to be inserted:\n ");
       scanf("%d",&num);
       if(l1.enqueue(num))
      {
         printf("\n %d is enqueued\n",num);
      }
      else
      {
       printf("\n %d is not enqueued\n",num);
      }
      break;

      case 2:
      value= l1.dequeue();
      if(value==1)
      {
        printf("\n Program executed");
         l1.display();
      }
      if(value==2)
      {
        printf("\n Program is getting executed  but not completely");
         l1.display();
      }
      if(value==3)
      {
        printf("\n Program cannot be executed");
      }
      break;
      
      case 3:
      exit(0);
       }
   }
  
   return 0;
}



//imlementation for enqueuing
int queue::enqueue(int num)
  {
   if(head==NULL && tail==NULL)
   {
      struct node* temp = (struct node*)malloc(sizeof(struct node));
      temp->data=num;
      head=tail=temp; 
      return 1;
   }
   else
   {
      struct node* ptr=(struct node*)malloc(sizeof(struct node));
      ptr->data=num;
      tail->next=ptr;
      tail=ptr;
      ptr->next=head;
      return 1;
   }
}

int queue::dequeue()
{
   
   int val1=head->data;
   if(head==NULL)
   {
       return 3;
   }
   else if (head==tail)
   {
       if((val1- fix)<=0)
       {
            head=tail=NULL;
            return 1;
       }
       else
       {
            head=tail=NULL;
            enqueue(val1- fix);
            return 2;
       }
       return 0;
   }
   else
   {
   
    if((val1-fix)<=0)
    {
        head=head->next;
        return 1;
    }
    if((val1-fix)>0)
    {
        head=head->next;
        enqueue(val1-fix);
        return 2;
    }
    return 0;
   }
   return 0;
}

void queue::peek()
{
   if(head==NULL)
   {
       printf("Queue is empty");
   }
   else
   {
       printf("%d is the topmost element",head->data);
   }

}
void queue::display()
{
    if(head==NULL)
    {
        printf("No elements found");
    }
    else
    {
       /* while(temp!=NULL&&temp->next!=tail->next)
        {
            printf(" %d ",temp->data);
            temp=temp->next;
        }*/
       printf("  \nFRONT: %d ",head->data);
       printf("  \nREAR: %d",tail->data);
    }
}