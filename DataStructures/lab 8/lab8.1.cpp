// Program to implement Tree ADT using linked lists
#include <stdio.h>
#include <stdlib.h>

class tree
{
    struct node
    {
        int data;
        struct node *left, *right;
    };

public:
    struct node *root;
    tree()
    {
        root = NULL;
    }
    int insert(int);
    int delete_num(int);
    int delete_num(int, struct node *);
    struct node *del_search(int, struct node *);
    void preorder();
    void preorder(struct node *);
    void inorder();
    void inorder(struct node *);
    void postorder();
    void postorder(struct node *);
    int search(int);
    int search(int, struct node *);
    struct node *findparent(struct node *, struct node *);
};

int main()
{
    int n, num, p, d;
    tree t1;
    while (1)
    {
        printf("\n\nEnter\n1. Insert\n2. Delete\n3. Preorder\n4. Inorder\n5. Postorder\n6. Search\n7. Exit: ");
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

        case 2:
            printf("\nEnter the number you want to delete: ");
            scanf("%d", &num);
            if (t1.delete_num(num))
                printf("Number deleted successfully");
            else
                printf("Deletion of number failed");
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
                printf("\n %d is found in the tree", num);
            }
            else
            {
                printf("\n %d is not found in the tree", num);
            }
            break;

        case 7:
            printf("\nThe program is terminated");
            exit(0);
            break;

        }
    }
}

// Method to insert a number in the tree
int tree::insert(int num)
{
    struct node *newnode = (struct node *)malloc(sizeof(struct node));
    if (root == NULL)
    {
        newnode->data = num;
        root = newnode;
        newnode->left = NULL;
        newnode->right = NULL;
        return 1;
    }
    else
    {
        int ch;
        struct node *temp = root;
        while (1)
        {
            printf("\nDo you want to go left (0) or right (1) ?");
            scanf("%d", &ch);
            if (ch == 0)
            {
                printf("in left");
                if (temp->left == NULL)
                {
                    temp->left = newnode;
                    newnode->data = num;
                    newnode->left = newnode->right = NULL;
                    return 1;
                }
                else
                {
                    temp = temp->left;
                }
            }
            else if (ch == 1)
            {
                if (temp->right == NULL)
                {
                    temp->right = newnode;
                    newnode->data = num;
                    newnode->left = newnode->right = NULL;
                    return 1;
                }
                else
                {
                    temp = temp->right;
                }
            }
        }
        return 0;
    }
}

//Method to delete a number from the tree
int tree::delete_num(int num)
{
    struct node *temp = del_search(num, root);
    struct node *parent = findparent(root, temp);

    if (temp == NULL)
        return 0;                                                        
    else if (temp->right == NULL && temp->left == NULL && parent == NULL) 
    {                                                                     
        free(temp);
        return 1;
    }
    else 
    {
        struct node *leafnode = root;
        while (true)
        {

            if (leafnode->left != NULL)
                leafnode = leafnode->left;
            if (leafnode->right != NULL)
                leafnode = leafnode->right;
            if (leafnode->right == leafnode->left)
                break;
        }

        parent = findparent(root, leafnode);

        int inttemp = 0;
        inttemp = leafnode->data;
        leafnode->data = temp->data;
        temp->data = inttemp;

        if (parent->right == leafnode)
            parent->right = NULL;
        else
            parent->left = NULL;
        free(leafnode);
        return 1;
    }
}

// Function to find the parent of a given node recursively
struct tree::node *tree::findparent(struct node *root1, struct node *temp)
{
    if (root1 == NULL || root1 == temp)
        return NULL;

    if (root1->left == temp || root1->right == temp)
        return root1;

    struct node *leftSearch = findparent(root1->left, temp);
    if (leftSearch)
        return leftSearch;

    struct node *rightSearch = findparent(root1->right, temp);
    if (rightSearch)
        return rightSearch;

    return NULL;
}

//Method to find the node containing the number we want to delete from the tree
struct tree::node* tree::del_search(int key,struct node* root)
{
    if (root == NULL || root->data == key)
        return root;

    struct node *left_search;
    left_search = del_search(key,root->left);
    if (left_search != NULL)
        return left_search;

    node *right_search;
    right_search = del_search(key,root->right);
    return right_search;
}

// Method to display in preorder
void tree::preorder()
{
    preorder(root);
}

void tree::preorder(struct node *temp)
{
    if (temp == NULL)
        return;
    else
    {
        printf("%d ", temp->data);
        preorder(temp->left);
        preorder(temp->right);
    }
}

// Method to display in inorder
void tree::inorder()
{
    inorder(root);
}

void tree::inorder(struct node *temp)
{
    if (temp == NULL)
        return;
    else
    {
        inorder(temp->left);
        printf("%d ", temp->data);
        inorder(temp->right);
    }
}

// Method to display in postorder
void tree::postorder()
{
    postorder(root);
}

void tree::postorder(struct node *temp)
{
    if (temp == NULL)
        return;
    else
    {
        postorder(temp->left);
        postorder(temp->right);
        printf("%d ", temp->data);
    }
}

// Method to search for an element in the tree
int tree::search(int num)
{
    search(num, root);
}

int tree::search(int num, struct node *temp)
{
    if (temp == NULL)
        return 0;
    else if (temp->data == num)
        return 1;
    else
    {
        if (search(num, temp->left))
            return 1;
        if (search(num, temp->right))
            return 1;
        return 0;
    }
}