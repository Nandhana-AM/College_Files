// Program to implement list adt usig singley linked lists
#include <stdio.h>
#include <stdlib.h>

class List
{
    struct node
    {
        int data;
        struct node *next;
    };

public:
    struct node *head;
    List()
    {
        head = NULL;
    }
    int insertbeg(int);
    void display();
    int insertend(int);
    int insertpos(int, int);
    int delbeg();
    int delend();
    int delpos(int);
    int search(int);
    void revdisp();
    int revlink();
};

int main()
{
    int num, pos, n, a;
    List l1;
    while (1)
    {
        printf("\nEnter\n1. Insertion in the beginning\n2. Insert in the end\n3.Insert at a position\n4. Delete beginning\n5. Delete end\n6. Delete position");
        printf("\n7. Search\n8. Display\n9. Display reverse\n10. Reverse link\n11. Exit: ");
        scanf("%d", &n);
        switch (n)
        {
        case 1:
            printf("\nEnter the number you want to insert: ");
            scanf("%d", &num);
            if (l1.insertbeg(num))
            {
                printf("\nNumber successfully inserted in the beginning.");
            }
            else
            {
                printf("\nInsertion in the begnning failed.");
            }
            break;

        case 2:
            printf("\nEnter the number you want to insert in the end: ");
            scanf("%d", &num);
            if (l1.insertend(num))
            {
                printf("\nInsertion at end successful.");
            }
            else
            {
                printf("Insertion failed.");
            }
            break;

        case 3:
            printf("\nEnter the positon of the number you want to insert: ");
            scanf("%d", &pos);
            printf("\nEnter the number you want to insert: ");
            scanf("%d", &num);
            if (l1.insertpos(pos, num))
            {
                printf("\nInsertion at position %d successful.", pos);
            }
            else
            {
                printf("\nInsertion at position %d failed.", pos);
            }
            break;

        case 4:
            if (a = l1.delbeg())
            {
                printf("\nBeginning number deleted successfully.");
                printf("\nThe deleted number is %d", a);
            }
            else
            {
                printf("\nDeletion of beginning element failed.");
            }
            break;

        case 5:
            if (a = l1.delend())
            {
                printf("\nEnd number deleted successfully.");
                printf("\nThe deleted number is %d", a);
            }
            else
            {
                printf("\nDeletion of the end number failed.");
            }
            break;

        case 6:
            printf("\nEnter the position of the number you want to delete: ");
            scanf("%d", &pos);
            if (a = l1.delpos(pos))
            {
                printf("\nThe number at position %d is successfully deleted.", pos);
                printf("\nThe deleted number is %d", a);
            }
            else
            {
                printf("\nDeletion of the number at position %d failed.", pos);
            }
            break;

        case 7:
            printf("\nEnter the number you want to search: ");
            scanf("%d", &num);
            int a;
            if (a = l1.search(num))
            {
                printf("\nThe number was found at position %d", a);
            }
            else
            {
                printf("\nThe number was not found.");
            }
            break;

        case 8:
            printf("\nThe numbers in the list are: ");
            l1.display();
            break;

        case 9:
            printf("\nThe list displayed in reverse is: ");
            l1.revdisp();
            break;

        case 10:
            if (l1.revlink())
            {
                printf("\nThe link is successfully reversed.");
            }
            else
            {
                printf("\nFailed to reverse the list.");
            }
            break;

        case 11:
            printf("\nThe program is terminated.");
            exit(0);
            break;
        }
    }
}

// Method to insert a number in the beginning of the list : O(1)
int List::insertbeg(int num)
{
    struct node *newnode;
    newnode = (struct node *)malloc(sizeof(struct node));
    if (head == NULL)
    {
        newnode->data = num;
        newnode->next = NULL;
        head = newnode;
        return 1;
    }
    else
    {
        newnode->data = num;
        newnode->next = head;
        head = newnode;
        return 1;
    }
}

// Method to insert a number in the end of the list
int List::insertend(int num)
{
    struct node *newnode;
    newnode = (struct node *)malloc(sizeof(struct node));
    struct node *temp = head;
    if (head == NULL)
    {
        insertbeg(num);
        return 1;
    }
    else
    {
        while (temp->next != NULL)
        {
            temp = temp->next;
        }
        newnode->data = num;
        newnode->next = temp->next;
        temp->next = newnode;
        return 1;
    }
}

// Method to insert a number in a specific position of the list
int List::insertpos(int pos, int num)
{
    struct node *newnode;
    newnode = (struct node *)malloc(sizeof(struct node));
    struct node *temp = head;
    int count = 0;
    while (temp != NULL)
    {
        count += 1;
        temp = temp->next;
    }
    if (pos < 1 || pos > count + 1)
    {
        return 0;
    }
    else if (pos == 1)
    {
        insertbeg(num);
        return 1;
    }
    else
    {
        temp = head;
        for (int i = 2; i < pos; i++)
        {
            temp = temp->next;
        }
        newnode->data = num;
        newnode->next = temp->next;
        temp->next = newnode;
        return 1;
    }
}

// Method to display the numbers in the list
void List::display()
{
    struct node *temp;
    temp = head;
    while (temp != NULL)
    {
        printf("%d ", temp->data);
        temp = temp->next;
    }
}

// Method to delete the beginning number
int List::delbeg()
{
    if (head == NULL)
    {
        return 0;
    }
    else
    {
        int a;
        a = head->data;
        head = head->next;
        return a;
    }
}

// Method to delete the last number
int List::delend()
{
    if (head == NULL)
    {
        return 0;
    }
    else if (head->next == NULL)
    {
        int a;
        a = delbeg();
        return a;
    }

    struct node *ptr = head;
    struct node *temp = head->next;
    while (temp->next != NULL)
    {
        temp = temp->next;
        ptr = ptr->next;
    }
    int a = temp->data;
    free(temp);
    ptr->next = NULL;
    return a;
}

// Method to delete a number in the specified position
int List::delpos(int pos)
{
    struct node *temp = head;
    int count = 0;
    while (temp != NULL)
    {
        count += 1;
        temp = temp->next;
    }
    if (head == NULL)
    {
        return 0;
    }
    else if (pos < 1 || pos > count)
    {
        return 0;
    }
    else if (pos == 1 && head->next == NULL)
    {
        int a = delbeg();
        return a;
    }
    else
    {
        int a;
        struct node *ptr;
        ptr = head;
        struct node *temp;
        temp = ptr->next;
        for (int i = 2; i < pos; i++)
        {
            temp = temp->next;
            ptr = ptr->next;
        }
        ptr->next = temp->next;
        a = temp->data;
        free(temp);
        return a;
    }
}

// Method to search a number in the list
int List::search(int num)
{
    int count = 0;
    struct node *temp = head;
    while (temp != NULL)
    {
        count += 1;
        if (num == temp->data)
        {
            return count;
        }
        temp = temp->next;
    }
    return 0;
}

// Method to disdplay reverse
void List::revdisp()
{
    revlink();
    display();
    revlink();
}

// Method to reverse the list
int List::revlink()
{
    struct node *cur = head;
    struct node *prev = NULL;
    struct node *next = NULL;
    if (head = NULL)
    {
        return 0;
    }
    else
    {
        while (cur != NULL)
        {
            next = cur->next;
            cur->next = prev;
            prev = cur;
            cur = next;
        }
        head = prev;
        return 1;
    }
}