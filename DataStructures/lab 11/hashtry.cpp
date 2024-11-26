#include <stdio.h>
#include <stdlib.h>
#define size 10

class hash
{
    struct node
    {
        int data;
        struct node* next;
    };
    struct node* array[size];

    public:
    hash()
    {
        for(int i=0;i<size;i++)
        {
            array[i]=NULL;
        }
    }

    int insert(int);
    int del(int);
    int search(int);
    void display();

};

int main()
{
    int num, n, a;
    hash h1;
    while (1)
    {
        printf("\nEnter\n1. Insert\n2. Delete\n3. Search\n4. Display\n5. Exit: ");
        scanf("%d", &n);
        switch (n)
        {
        case 1:
            printf("\nEnter the number you want to insert: ");
            scanf("%d", &num);
            if (h1.insert(num))
            {
                printf("\nNumber successfully inserted.");
            }
            else
            {
                printf("\nInsertion failed.");
            }
            break;

        case 2:
            printf("Enter the number you want to delete: ");
            scanf("%d",&num);
            if (h1.del(num))
            {
                printf("\nThe number is successfully deleted.");
            }
            else
            {
                printf("\nDeletion of the number failed.");
            }
            break;

            case 3:
                printf("\nEnter the number you want to search: ");
                scanf("%d", &num);
                int a;
                if (a = h1.search(num))
                {
                    printf("\nThe number was found in the hash.");
                }
                else
                {
                    printf("\nThe number was not found.");
                }
                break;

            case 4:
                printf("\nThe numbers in the list are:\n");
                h1.display();
                break;

        case 5:
            printf("\nThe program is terminated.");
            exit(0);
            break;
        }
    }
}

int hash::insert(int num)
{
    struct node *newnode = (struct node *)malloc(sizeof(struct node));
    int e = num % size;
    struct node* temp=array[e];
    if (array[e]==NULL) 
    {
        newnode->data=num;
        newnode->next=NULL;
        array[e]=newnode;
        return 1;
    }
    else
    {
        while(temp->next!=NULL)
        {
            temp=temp->next;
        }
        newnode->data=num;
        newnode->next=NULL;
        temp->next=newnode;
        return 1;
    }
}

int hash::del(int num)
{
    int e = num % size;
    struct node* ptr=array[e];
    struct node* temp=ptr->next;
    if (array[e]==NULL) return 0;
    else if (array[e]->data==num) array[e]=NULL;
    else
    {
        while(temp!=NULL)
            if(temp->data==num)
            {
                ptr->next=temp->next;
                free(temp);
                return 1;
            }
            else 
            {
                temp=temp->next;
                ptr=ptr->next;
            }
    }
}

int hash::search(int num)
{
   int e = num % size;
    struct node *temp = array[e];
    if (array[e] == NULL)
        return 0;
    else
    {
        while (temp != NULL)
        {
            if (temp->data == num) return 1;
            else temp=temp->next;
        }
        return 0;
    }
}

void hash::display()
{
    for (int i=0;i<size;i++)
    {
        printf("%d ->",i);
        struct node* temp=array[i];
        while (temp!=NULL)
        {
            printf("%d ",temp->data);
            temp=temp->next;
        }
        printf("\n");
    }
}