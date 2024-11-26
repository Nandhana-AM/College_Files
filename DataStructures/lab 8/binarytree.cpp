#include <stdio.h>
#include <stdlib.h>

//Tree implementation using doubly linked list
class dict{
    struct node{
        struct node* right;
        int data;
        struct node* left;
    };
    struct node* root;
    public:
    dict(){
        root=NULL;
    }
    int insert(int,struct node*);
    int preorder(struct node*);
    int postorder(struct node*);
    int inorder(struct node*);
    int search(int,struct node*);
    int deleted(int,struct node*);
};
//Method to insert in a tree. 0(N)
int dict::insert(int value,struct node* temp=NULL){
    if(root==NULL){
        struct node* new1=(struct node*)malloc(sizeof(struct node));
        new1->left=NULL;
        new1->data=value;
        new1->right=NULL;
        root=new1;
        return 1;
    }
    else{
        int n;
        if(temp==NULL){
            struct node* new1=(struct node*)malloc(sizeof(struct node));
            new1->left=NULL;
            new1->right=NULL;
            new1->data=value;
            temp=root;
            printf("Enter 1-left or 2-right:");
            scanf("%d",&n);
            if(n==1){
                if(temp->left==NULL){
                    temp->left=new1;
                    return 1;
            }
                else{
                    return insert(value,temp->left);
                }
            }
            else if(n==2){
                if(temp->right==NULL){
                    temp->right=new1;
                    return 1;
                }
                else{
                    return insert(value,temp->right);
                }
            }
        }
        else{
            struct node* new1=(struct node*)malloc(sizeof(struct node));
            new1->left=NULL;
            new1->right=NULL;
            new1->data=value;
            printf("Enter 1-left or 2-right:");
            scanf("%d",&n);
            if(n==1){
                if(temp->left!=NULL){
                    return insert(value,temp->left);
            }
            else{
                temp->left=new1;
                return 1;
            }
            }
            else{
                if(temp->right!=NULL){
                    return insert(value,temp->right);
                    }
                else{
                    temp->right=new1;
                    return 1;
            }
        }
        }
    }
    return 0;
}
//Method to print the result in preorder.0(N)
int dict::preorder(struct node* temp=NULL){
    if(root==NULL){
        return 0;
    }
    else{
       if(temp==NULL){
           temp=root;
           printf("%d ",temp->data);
           if(temp->left!=NULL){
               preorder(temp->left);
           }
           if(temp->right!=NULL){
               preorder(temp->right);
           }
           
       }
       else{
           printf("%d ",temp->data);
           if(temp->left!=NULL){
               preorder(temp->left);
           }
           if(temp->right!=NULL){
             preorder(temp->right);
           }
           
           
       }
    }
    return 1;
}
//Method to print the result in inorder.0(N)
int dict::inorder(struct node* temp=NULL){
    if(root==NULL){
        return 0;
    }
    else{
        if(temp==NULL){
            temp=root;
            if(temp->left!=NULL){
                inorder(temp->left);
            }
            printf("%d ",temp->data);
            if(temp->right!=NULL){
                inorder(temp->right);
            }
        }
        else{
            if(temp->left!=NULL){
                inorder(temp->left);
            }
            printf("%d ",temp->data);
            if(temp->right!=NULL){
                inorder(temp->right);
            }
           
        }
    }
   return 1;
}
//Method to print the result in postorder.0(N)
int dict::postorder(struct node* temp=NULL){
    if(root==NULL){
        return 0;
    }
    else{
        if(temp==NULL){
            temp=root;
            if(temp->left!=NULL){
                postorder(temp->left);
            }
            if(temp->right!=NULL){
                postorder(temp->right);
            }
            printf("%d ",temp->data);
        }
        else{
            if(temp->left!=NULL){
                postorder(temp->left);
            }
            if(temp->right!=NULL){
                postorder(temp->right);
            }
            printf("%d ",temp->data);
        }
    }
   return 1;
}
//Method to search a given element in the tree.0(N)
int dict::search(int value,struct node* temp=NULL){
    if(root==NULL){
        return 0;
    }
    else{
        if(temp==NULL){
            temp=root;
        }
        if(temp->left!=NULL){
           search(value,temp->left);
        }
        else{
            if(temp->data==value){
                return 1;
            }
        }
        if(temp->right!=NULL){
            search(value,temp->right);
        }
        else{
            if(temp->data==value){
                return 1;
            }
        }
        return 0;
    }
}
//Method to delete a given element in the tree.0(n)
int dict::deleted(int value,struct node* temp=NULL){
    if(root==NULL){
        return 0;
    }
    else{
        if(temp==NULL){
            temp=root;
            
        }
        if(temp->data==value && temp==root){
            if (temp->left == NULL && temp->right == NULL) {
            if (temp == root) {
                delete temp;
                root = NULL;
                return 1;
            }
            else{
                int temp2;
                struct node* temp1=root;
                while(temp1->left!=NULL){
                 temp1=temp1->left;
            }
                temp2=temp->data;
                temp->data=temp1->data;
                temp1->data=temp2;
                temp=root;
                while(temp->left!=temp1){
                 temp=temp->left;
            }
                temp->left=NULL;
                return 1;
            }
        }
        else if(temp->data==value && temp->left!=NULL && temp->right!=NULL){
            int temp2;
            struct node* temp1=root;
            while(temp1->left!=NULL){
                temp1=temp1->left;
            }
            temp2=temp->data;
            temp->data=temp1->data;
            temp1->data=temp2;
            temp=root;
            while(temp->left!=temp1){
                temp=temp->left;
            }
            temp->left=NULL;
            return 1;
        }
        else if(temp->data==value &&((temp->left!=NULL && temp->right==NULL) || (temp->left==NULL && temp->right!=NULL))){
            if(temp->left!=NULL && temp->right==NULL){
                int temp2=temp->left->data;
                temp->left->data=temp->data;
                temp->data=temp2;
                temp->left=NULL;
                return 1;
            }
            else{
                int temp2=temp->right->data;
                temp->right->data=temp->data;
                temp->data=temp2;
                temp->right=NULL;
                return 1;
            }
                
        }
        else if(temp->left!=NULL && temp->left->data==value){
                if(temp->left->left==NULL && temp->left->right==NULL){
                    delete temp->left;
                    temp->left=NULL;
                    return 1;
                 }
        }
        else if(temp->right!=NULL && temp->right->data==value){
                if(temp->right->right==NULL && temp->right->left==NULL){
                    delete temp->right;
                    temp->right=NULL;
                    return 1;
                 }
        }
    
        else{
            if(temp->left!=NULL){
                temp=temp->left;
                return deleted(value,temp);
            }
            if(temp->right!=NULL){
                temp=temp->right;
                return deleted(value,temp);
            }
        }}
    
    return 0;
    
}}

int main(){
    int choice, num;
    dict d;
    while(1){
        printf("\n1. Insert\n2. Preorder\n3. Inorder\n4.Postorder\n5.Search\n6.Delete\n7.Exit\nEnter your choice: ");
        scanf("%d",&choice);
        switch (choice) {
        case 1:
            printf("Enter element to add: ");
            scanf("%d",&num);
            if (d.insert(num)) {
                printf("Element added successfully.");
            }
            else {
                printf("Failed to add element.");
            }
            break;
        case 2:
       
            if(d.preorder()){
                printf(":The Elements of the tree\n");
            }
            else{
                printf("No elements in the tree");
            }
            break;
         case 3:
       
            if(d.inorder()){
                printf(":The Elements of the tree\n");
            }
            else{
                printf("No elements in the tree");
            }
            break;
        case 4:
       
            if(d.postorder()){
                printf(":The Elements of the tree\n");
            }
            else{
                printf("No elements in the tree");
            }
            break;
        case 5:
            printf("Enter the value you wanna search:");
            scanf("%d",&num);
            if(d.search(num)){
                printf("The element is present in the binary tree");
            }
            else{
                printf("The element isnt present in the binary tree");
            }
            break;
        case 6:
             printf("Enter the value you want to delete in the tree:");
             scanf("%d",&num);
             if(d.deleted(num)){
                 printf("The element was successfully deleted from the tree");
             }
             else{
                 printf("The element isnt present in the tree");
             }
             break;
        case 7:
            printf("Exiting program.");
            exit(0);
        default:
            printf("Invalid choice.");
        }}
    return 0;
}