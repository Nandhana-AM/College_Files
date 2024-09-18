public class methods implements functions
{
    int arr[];
    int front,rear;
    methods()
    {
        arr = new int[5];
        front=-1;
        rear=-1;
    }

    public int enqueue(int num)
    {
        if(rear==4)
            return 0;
        else if (front==-1 & rear==-1)
        {
            front++;
            rear++;
            arr[rear]=num;
            return 1;
        }
        else
        {
            rear++;
            arr[rear]=num;
            return 1;
        }
    }

    public int dequeue()
    {
        if(front==-1)
            return 0;
        else if(front>rear)
        {
            return 0;
        }
        else 
        {
            int deq=arr[front];
            front+=1;
            return deq;
        }
    }

    public void peek()
    {
        if (front==-1)
            System.out.println("\nThe queue is empty");
        else
            System.out.println("The front is "+arr[front]+" and rear is "+arr[rear]);
    }
}
