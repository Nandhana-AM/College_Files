//Header to implement round robin's schedule using circular linked lists
#include <stdio.h>
#include <stdlib.h>
#define reftime 5

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
};

//Method to get an integer time and add it to the queue
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

//Method to execute a process from the queue
int queue::deq()
{
    if (front==NULL)
    {
        return 3;
    }
    if (front==rear)
    {
        int p=front->data;
        if ((p-reftime)<=0)
        {
            front=rear=NULL;
            return 1;
        }
        else if (p-reftime>0)
        {
            front=rear=NULL;
            enq(p-reftime);
            return 2;
        }
        return 0;
    }
    else
    {
        int p=front->data;
        if ((p-reftime)<=0)
        {
            front=front->next;
            return 1;
        }
        else if (p-reftime>0)
        {
            front=front->next;
            enq(p-reftime);
            return 2;
        }
        return 0;
    }
    return 0;
}