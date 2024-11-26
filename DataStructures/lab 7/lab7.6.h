//Header to implement queue adt using circular linked lists
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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
    int enq(char);
    void string(char*);
    int deq();
    void process();
    void peek();
};

//Method to add an element to the queue
int queue::enq(char c)
{
    struct node* newnode=(struct node*)malloc(sizeof(struct node));
    if(front==NULL and rear==NULL)
    {
        newnode->data=c;
        newnode->next=NULL;
        front=rear=newnode;
        return 1;
    }
    else
    {
        newnode->data=c;
        newnode->next=NULL;
        rear->next=newnode;
        rear=newnode;
        return 1;
    }
}

//Method to store the string in a queue
void queue::string(char* str)
{
    char c=*str;
    int b=strlen(str);
    for (int i=0;i<=b;i++)
    {
        c=*(str+i);
        enq(c);
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

//Method to proccess the queue
void queue::process()
{
    struct node* temp=front;
    while(temp->next!=NULL)
    {
        if(temp->next->data=='+')
        {
            deq();
        }
        else if(temp->data=='+')
        {
            deq();
        }
        else
        {
            printf("%c",temp->data);
        }
        temp=temp->next;
    }
    front=rear=NULL;
}