#include <stdio.h>
#include <stdlib.h>

class list
{
    struct node
    {
        int data;
        struct node* next;
    };
    public:
    struct node* head;
    list()
    {
        head=NULL;
    }
    
    int insert(int);
    void sort();
    void merge(list&,list&);
    void display();
    struct node* gethead();
};

int list::insert(int num)
{
    struct node* newnode;
    newnode=(struct node*)malloc(sizeof(struct node));
    newnode->data=num;
    newnode->next=head;
    head=newnode;
    sort();
    return 1;
}
void list::sort()
{
    struct node *temp1,*temp2;
    temp1=head;
    int temp3;
    while (temp1!=NULL)
    {
        temp2=temp1->next;
        while(temp2!=NULL)
        {
            if (temp2->data<temp1->data)
            {
                temp3=temp1->data;
                temp1->data=temp2->data;
                temp2->data=temp3;
            }
            temp2=temp2->next;
        }
        temp1=temp1->next;
    }
}

void list::display()
{
    struct node* temp;
    temp=head;
    while (temp!=NULL)
    {
        printf("%d ",temp->data);
        temp=temp->next;
    }
}

struct list::node* list::gethead()
{
    return head;
}

void list::merge(list& l1,list& l2)
{
    while(head!=NULL)
    {
        head=head->next;
        free(head);
    }
    struct node*head1=l1.gethead(),*head2=l2.gethead();
    struct node*temp1=head1,*temp2=head2;
    while(temp1!=NULL)
    {
        insert(temp1->data);
        temp1=temp1->next;
    }
    while (temp2!=NULL)
    {
        insert(temp2->data);
        temp2=temp2->next;
    }
    sort();
}