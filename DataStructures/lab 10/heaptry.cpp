#include <stdio.h>
#include <stdlib.h>
#define size 100

class heap
{
    int cur;
    int array[size];

    public:
    heap()
    {
        cur=-1;
    }

    int insert(int);
    void heapify();
    int del();
    void display();
    int search(int);
    void heapsort();
};

int main()
{
    heap h1;
    int num,ch;
    while(1)
    {
        printf("\nEnter\n1. Insert\n2. Delete\n3. Display\n4. Search\n5. Heap sort\n6. Exit:");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1:
            printf("\nEnter the number to insert: ");
            scanf("%d",&num);
            if (h1.insert(num)) printf("\n%d was successfully inserted :)",num);
            else printf("\nInsertion of %d failed :(");
            break;

            case 2:
            if (h1.del()) printf("\nRoot %d deleted successfully :)",num);
            else printf("\nDeletion of root unsuccessful :(");
            break;

            case 3:
            h1.display();
            break;

            case 4:
            printf("\nEnter the number you wanna search: ");
            scanf("%d",&num);
            int p;
            p=h1.search(num);
            if (p==-1) printf("\n%d not found in the heap :(");
            else printf("\n%d successfully found in the heap at index %d :)",num,p);
            break;

            case 5:
            h1.heapsort();
            break;
            
            case 6:
            exit(0);

        }
    }
}

void heap::heapify()
{
    int i=cur;
    while(i>0)
    {
        int parent=(i-1)/2;
        if (array[i]>array[parent])
        {
            int temp=array[i];
            array[i]=array[parent];
            array[parent]=temp;
        }
        i--;
    }
}

int heap::insert(int num)
{
    if (cur==100) return 0;
    else
    {
        cur++;
        array[cur]=num;
        heapify();
        return 1;
    }
}

int heap::del()
{
    if (cur==-1) return 0;
    else
    {
          int temp=array[0];
          array[0]=array[cur];
          cur--;
          heapify();
          return temp;
    }
}

void heap::display()
{
    if (cur==-1) printf("\nThe heap is empty!");
    else 
    {
        printf("\nThe numbers in the heap are: ");
        for (int i=0;i<=cur;i++)
        {
            printf("%d ",array[i]);
        }
    }
}

int heap::search(int num)
{
    if (cur==-1) return -1;
    else
    {
        int i=cur;
        for(int i=0;i<=cur;i++)
        {
            if (array[i]==num) return i;
            else i++;
        }
        return -1;
    }
}

void heap::heapsort()
{
    if (cur==-1) printf("\nThe heap is empty.");
    else
    {
        printf("\nHeapsort of maxheap: ");
        while(cur>=0)
        {
            printf("%d ",del());
        }
    }
}