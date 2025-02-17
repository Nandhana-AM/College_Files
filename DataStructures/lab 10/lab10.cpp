/*
A. Write a separate C++ menu-driven program to implement Priority Queue ADT using a max heap. Maintain proper boundary conditions and follow good coding practices. The Priority Queue ADT has the following operations,

1. Insert
2. Delete
3. Display
4. Search
5. Sort (Heap Sort) 
6. Exit

What is the time complexity of each of the operations?
*/




#include <stdio.h>
using namespace std;
#include<stdlib.h>
#include<queue>
#define SIZE 50
class heap {
    int arr[SIZE];
    int cur;
    public:
        heap() {
            cur = -1;
        }
    int insert(int num);
    void heapify();
    void display();
    int del();
    void sort(queue <int> q1);
    void displayq(queue <int> q1);
    int search(int num);
    
        
};

int main() {
    queue <int> q1; 
    heap h1;
    int choice;
    int element;
    int pos;
    while(1) {

        printf("\n PRIORITY QUEUE ADT \n");
        printf("\n 1. Insert \n 2. Delete \n 3. Display \n 4. Search \n 5. Sort \n 6. Exit");
        scanf("%d",&choice);

        switch(choice) {
            case 1:
                printf("Enter the character ");
                scanf(" %d",&element);
                if(h1.insert(element)) {
                    printf("\n Inserted successfully.\n");
                }
                else {
                    printf("\n Insertion unsuccessful.\n");
                }
                break;
            
            case 2:
                if(h1.del()) {
                printf("Element deleted successfully");
                }

                else {   
                printf("The heap is empty");
                }
                break;
            
            case 3:
                h1.display();
                break;

            case 4:
                int num;
                printf("Enter the number to search");
                scanf("%d",&num);
                if(h1.search(num)) {
                    printf("the number is in %d",h1.search(num));
                }

                else {
                    printf("The element is not found.");
                }
                break;
            
            case 5:
                h1.sort(q1);
                break; 
           
            case 6:
                return 0;

        }
    }

}

//Method to push into heap.
//Time complexity => O(logn).
int heap:: insert(int num) {

  if (cur==SIZE-1) {
    return 0;
  }

  else if(cur==-1) {
    arr[0]=num;
    cur++;
    return 1;
}
  else {
    cur++;
    arr[cur]=num;
    heapify();
    return 1;
  }
}

//Method for heapify.
void heap:: heapify() 
{
     int i=cur;     
     while(i>0) 
     {
        int parent=(i-1)/2;
        if(arr[i]>arr[parent]) 
        {
          int temp=arr[i];
          arr[i]=arr[parent];
          arr[parent]=temp;
        }
        i--;
        
     } 
  }

//Method to display the elements.
//Time complexity => O(n).
void heap::display() {
  
  for(int i=0;i<=cur;i++) {
    printf("%d\t",arr[i]);
  }
}

//Method to delete.
//Time complexity => O(logn).
int heap:: del() {
  if(cur==-1) {
    return '\0';
  }

  else {
    int temp=arr[0];
    arr[0]=arr[cur];
    cur--;
    heapify();
    return temp;
  }
}

//Method to sort the heap.
//Time complexity => O(nlogn).
void heap::sort(queue<int>q1) {
  while(cur!=-1) {
    q1.push(del());
  }
   displayq(q1);
}

void heap:: displayq(queue<int> q1) {
    queue<int>q2 = q1;
    while (!q2.empty()) {
        printf("\n%d\n",q2.front());
        q2.pop();
    }

}

//Method to search.
//Time complexity => O(n).
int heap:: search(int num) {
  for(int i=0;i<=cur;i++) {
    if(num==arr[i]) {
      return i+1;
    }
  }
  return 0;

}