#include <stdio.h>
#include <stdlib.h>

class tree
{
    struct node
    {
        int data;
        struct node* left;
        struct node* right;
    };
    struct node* root;

    public:
    tree()
    {
        root=NULL;
    }

    int insert(int);
    int search(int);
    int search(int,struct node*);
    void preorder(); //R0 L R
    void preorder(struct node*);
    void inorder(); //L R0 R
    void inorder(struct node*);
    void postorder(); //L R R0
    void postorder(struct node*);
};

int main()
{
    int n, num, p, d;
    tree t1;
    while (1)
    {
        printf("\n\nEnter\n1. Insert\n3. Preorder\n4. Inorder\n5. Postorder\n6. Search\n7. Exit: ");
        scanf("%d", &n);
        switch (n)
        {
        case 1:
            printf("\nEnter the number you want to insert: ");
            scanf("%d", &num);
            if (t1.insert(num))
            {
                printf("\n%d is successfully added to the tree", num);
            }
            else
            {
                printf("\nInsertion failed");
            }
            break;

        case 3:
            t1.preorder();
            break;

        case 4:
            t1.inorder();
            break;

        case 5:
            t1.postorder();
            break;

        case 6:
            printf("Enter the number you want to search: ");
            scanf("%d", &num);
            if (t1.search(num))
            {
                printf("\n%d is found in the tree", num);
            }
            else
            {
                printf("\n%d is not found in the tree", num);
            }
            break;

        case 7:
            printf("\nThe program is terminated");
            exit(0);
            break;

        }
    }
}

int tree::insert(int num)
{
    struct node* newnode=(struct node*)malloc(sizeof(struct node));
    if (root==NULL) 
    {
        newnode->data=num;
        newnode->left=NULL;
        newnode->right=NULL;
        root=newnode;
        return 1;
    }
    else
    {
        int ch;
        struct node* temp=root;
        struct node* newnode=(struct node*)malloc(sizeof(struct node));
        while(1)
        {
            printf("\nDo you wanna go left(1) or right(2) ? ");
            scanf("%d",&ch);
            if(ch==1) 
            {
                if (temp->left==NULL)
                {
                    temp->left=newnode;
                    newnode->data=num;
                    newnode->left=newnode->right=NULL;
                    return 1;
                }
                else temp=temp->left;
            }
            else if(ch==2) 
            {
                if (temp->right==NULL)
                {
                    temp->right=newnode;
                    newnode->data=num;
                    newnode->left=newnode->right=NULL;
                    return 1;
                }
                else temp=temp->right;
            }
            else if (ch!=1 && ch!=2) printf("\nInvalid choice!");
        }
        return 0;
    }
}

void tree::inorder()
{
    inorder(root);
}

void tree::inorder(struct node* root)
{
    if (root==NULL) return;
    else
    {
        inorder(root->left);
        printf("%d ",root->data);
        inorder(root->right);
    }
}

void tree::preorder()
{
    preorder(root);
}

void tree::preorder(struct node* root)
{
    if (root==NULL) return;
    else
    {
        printf("%d ",root->data);
        preorder(root->left);
        preorder(root->right);
    }
}

void tree::postorder()
{
    postorder(root);
}

void tree::postorder(struct node* root)
{
    if (root==NULL) return;
    else
    {
        postorder(root->left);
        postorder(root->right);
        printf("%d ",root->data);
    }
}

int tree::search(int num)
{
    search(num,root);
}

int tree::search(int num,struct node* root)
{
    if (root==NULL) return 0;
    else if (root->data==num) return 1;
    else
    {
        if (search(num,root->left)) return 1;
        else if (search(num,root->right)) return 1;
    }
}