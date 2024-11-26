//Program to implement Tree ADT using binary search tree
#include<stdio.h>
#include<stdlib.h>
class bst
{
    struct node 
    {
        int data;
        struct node *left;
        struct node *right;
    };
    struct node *root;


void inorder(struct node *root)
{
    if(root==NULL)
    {
        return;
    }
    else
    {
        inorder(root->left);
        printf("%d\t",root->data);
        inorder(root->right);
    }
}


    void preorder(struct node *root)
    {
        if(root==NULL)
        {
            return;
        }
        else
        {
            printf("%d\t",root->data);
            preorder(root->left);
            preorder(root->right);
        }
    }

    void postorder(struct node *root)
    {
        if(root==NULL)
        {
            return;
        }
        else
        {
            postorder(root->left);
            postorder(root->right);
            printf("%d\t",root->data);
        }
    }
int search(struct node *root,int num)
{
    if(root==NULL)
    {
        return 0;
    }
    else if (root->data==num)
    {
        return 1;
    }
    else
    {
        if(root->data>num)
        {
            search(root->left,num);
        }
        else 
        {
            search(root->right,num);
        }
    }
}

// Utility function to find the node with the minimum value in a subtree


struct node* delete_node(struct node* root, int num) {
    if (root == NULL)
     return NULL;

    if (num < root->data)
    {
        root->left = delete_node(root->left, num);
    } 
    else if (num >= root->data) 
    {
        root->right = delete_node(root->right, num);
    } 
    else 
    {
        // Node with one child or no child
        if (root->left == NULL &&root->right!=NULL) 
        {
            struct node* temp = root->right;
            free(root);
            return temp;
        } 
        
        else if (root->right == NULL&&root->right!=NULL)
       {
            struct node* temp = root->left;
            free(root);
            return temp;
        }

        // Node with two children: Get the inorder successor (smallest in the right subtree)
        struct node* temp = root->right;
        while(temp->left!=NULL)
        {
            temp=temp->left;
        }
        root->data = temp->data;
        root->right = delete_node(root->right, temp->data);
    }
    return root;
}

    public:
   
    bst()
    {
        root=NULL;
    }
  

    void callin()
    {
        inorder(root);
    }

    void callpre()
    {
        preorder(root);
    }

    void callpost()
    {
        postorder(root);
    }

    int callsearch(int num)
    {
        return search(root,num);
    }

    int calldelete(int num)
    {
         delete_node(root,num);
    }
    
    int insert(int num);
     
};

int main()
{
    bst b1;
    int choice;
    while(1)
    {
        printf("\n(1) Insert");
        printf("\n(2) Inorder");
        printf("\n(3) Preorder");
        printf("\n(4) Postorder");
        printf("\n(5) Search");
        printf("\n(6) Delete");
        printf("\n(7) Exit");
        printf("\n Enter your choice:");
        scanf("%d",&choice);

        switch (choice)
        {
            case 1:
       
            int num1;
            printf("Enter the number to insert:");
            scanf("%d",&num1);
            if(b1.insert(num1))
            {
                printf("Number is inserted successfully");
            }
            else
            {
                printf("Operation failed");
            }
            break;

            case 2:
            b1.callin();
            break;

            case 3:
            b1.callpre();
            break;

            case 4:
            b1.callpost();
            break;
           
            case 5:
            int num5;
            printf("Enter the number to search:");
            scanf("%d",&num5);
            if(b1.callsearch(num5))
            {
                printf("The number is found in the tree");
            }
            else
            {
                printf("The number is not found");
            }
            
            break;
            
            case 6:
            int num6;
            printf("Enter the number to delete:");
            scanf("%d",&num6);
            b1.calldelete(num6);
            break;

            case 7 :
            return 0;

        }
    }
}
int bst::insert(int num)
{
    struct node *temp=root;
    struct node *newnode=(struct node *)malloc(sizeof(struct node));
    newnode->data=num;
    newnode->left=NULL;
    newnode->right=NULL;
    if(root==NULL)
    {
        root=newnode;
        return 1;
    }
    
    else
    {
        while(1)
        {
        if(temp->data>num)
        {
            if(temp->left==NULL)
            {
                temp->left=newnode;
                return 1;
            }
            temp=temp->left;
    
        }
        else if(temp->data<=num)
        {
            if(temp->right==NULL)
            {
                temp->right=newnode;
                return 1;
            }
            temp=temp->right;
        }
    }
}
}

