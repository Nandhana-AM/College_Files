//Program to implement queue adt using circular linked lists
#include <stdio.h>
#include <stdlib.h>

class queue
{
    struct node
    {
        int data;
        struct node* next;
    };

    public:
    struct node* front,*rear;
    queue()
    {
        front=NULL;
        rear=NULL;
    }
    int enq(int);
    int deq();
    void peek();
};

int main()
{
    int num,p;
    int n;
    queue q1,q2;
    while(1)
    {
        printf("\n\nEnter\n1. To add an element\n2. To remove an element\n3. To peek\n4. Exit: ");
        scanf("%d",&n);
        switch(n)
    {
        case 1: 
        printf("Enter the element you want to add: ");
        scanf("%d",&num);
        if (q1.enq(num))
        {
            printf("\n%d is successfully added to the queue",num);
        }
        else
        {
            printf("\nThe queue is full");
        }
        break;

        case 2:
        if (p=q1.deq())
        {
            printf("\nThe front element %d is removed",p);
        }
        else
        {
            printf("\nThe queue is empty");
        }
        break;

        case 3:
        q1.peek();
        break;

        case 4:
        printf("\nThe program is terminated");
        exit(0);
        break;
    }
    }
}

//Method to add an element to the queue
int queue::enq(int num)
{
    struct node* newnode=(struct node*)malloc(sizeof(struct node));
    if(front==NULL and rear==NULL)
    {
        newnode->data=num;
        front=rear=newnode;
        rear->next=front;
        return 1;
    }
    else
    {
        newnode->data=num;
        rear->next=newnode;
        rear=newnode;
        rear->next=front;
        return 1;
    }
}

//Method to remove an element from the queue
int queue::deq()
{
    if (front==NULL)
    {
        return 0;
    }
    if (front==rear)
    {
        int p=front->data;
        front=rear=NULL;
        return p;
    }
    else
    {
        int p=front->data;
        front=front->next;
        return p;
    }
}

void queue::peek()
{
    if (front==NULL)
    {
        printf("\nThe queue is empty.");
    }
    else
    {
        printf("\nThe front element is %d",front->data);
        printf("\nThe rear element is %d",rear->data);
    }
}