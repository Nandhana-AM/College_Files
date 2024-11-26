//Implementaion of circular queue ADT using array

#include <stdio.h>
#include <stdlib.h>
#define size 5

class queue
{
    int arr[size];
    int front,rear;
    public:
    queue()
    {
        front=rear=-1;
    }
    int enq(int);
    int deq();
    void peek();
    //void display();
};

int main()
{
    int num,p;
    int n;
    queue q1,q2;
    while(1)
    {
        printf("\nEnter\n1. To add an element\n2. To remove an element\n3. To peek\n5. Exit: ");/*\n4. Display*/
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

        // case 4:
        // q1.display();
        // break;

        case 5:
        printf("\nThe program is terminated");
        exit(0);
        break;
    }
    }
}

//Method to add an element into the queue
int queue::enq(int num)
{
    if((rear+1)%size==front)
    {
        return 0;
    }
    if(rear==-1)
    {
        front++;
        rear++;
        arr[0]=num;
        return 1;
    }
    else
    {
        rear=(rear+1)%size;
        arr[rear]=num;
        return 1;
    }
}

//Method to remove an element from the queue
int queue::deq()
{
    if (front==-1)
    {
        return 0;
    }
    else if (front==rear)
    {
        int p=arr[front];
        front=-1;
        rear=-1;
        return p;
        
    }
    else
    {
        int p=arr[front];
        front=(front+1)%size;
        return p;
    }

}

//Method to peek at the front and rear value 
void queue::peek()
{
    if (front==-1)
    {
        printf("\nThe stack is empty");
    }
    else
    {
        printf("\nthe front element is %d",arr[front]);
        printf("\nthe rear element is %d",arr[rear]);
    }
}

//Method to display the queue
// void queue::display()
// {
//     if (front==-1)
//     {
//         printf("\nThe queue is empty");
//     }
//     else
//     {
//         for (int i=0;i<size;i++)
//         {
//             printf("%d ",arr[i]);
//         }
//     }
// }