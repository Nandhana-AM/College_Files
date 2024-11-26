//Implementing a graph with an adjacency list
#include<stdio.h>
#include<stdlib.h>

class graph
{
	struct node 
	{
		int vertex;
		struct node * next;
		struct node * nextvertex;
	};
	struct node * root = NULL;
	public:
		int insert(int);
		int del(int);
		void display();
		int search(int);
};
int main()
{
	int num,opp;
	graph g1;
	while(1)
	{
		printf("\n enter the option \n 1.INSERT\n2.DELETE\n3.DISPLAY\n4.SEARCH");
		scanf("%d",&opp);
		switch(opp)
		{
			case 1:
			printf("\n enter the vertex to enter");
			scanf("%d",&num);
			if(g1.insert(num))
			{
				printf("\n DONE RA");
			}
			else
			{
				printf("\n MUDINCHU");
			}
				break;
			case 2:
				break;
			case 3:
				g1.display();
				break;
			case 4:
				break;
			default:
			printf("\n INVALID OPTION");
			break;
		}
		
	}
}
int graph::insert(int num)
{
	struct node * temp = root;
	while(temp!=NULL)
	{
		if(num==temp->vertex)
		{
			return 0;
		}
		temp = temp->nextvertex;
	}
	struct node * newnode = (struct node *)malloc(sizeof(struct node));
	newnode->vertex = num;
	newnode->next = NULL;
	newnode->nextvertex = NULL;
	if(root==NULL)
	{
		root = newnode;
		
	}
	else
	{
		newnode->nextvertex = root;
		root = newnode;
	}
	int choice;
	struct node * temp2 = newnode;
	temp = root;

	while(temp!=NULL)
	{
		printf("\n Is there a connection between %d and %d: ",num,temp->vertex);
		scanf("%d",&choice);
		if(choice!=1 && choice!=0)
		{
			printf("\n INVALID CHOICE");
		}
		if(choice==1)
		{
				struct node * newnode2 = (struct node *)malloc(sizeof(struct node));
				newnode2 -> vertex = temp->vertex;
				newnode2 -> next = NULL;
				newnode2 ->nextvertex = NULL;
				temp2->next = newnode2;
				temp2 = temp2->next;
				
				if(num!=temp->vertex)
				{
					
				
				struct node * temp3 = temp;
				struct node * newnode3 = (struct node *)malloc(sizeof(struct node));
				newnode3->vertex = num;
				newnode3->next = NULL;
				newnode3->nextvertex = NULL;
			/*	while(temp3->next!=NULL)
				{
					temp3 = temp3->next;
				}
				*/
				newnode3->next = temp3->next;
				temp3->next = newnode3;
			}
				
		
		}
		temp = temp->nextvertex;
	}
	return 1;
	
	
}
void graph::display()
{
	if(root==NULL)
	{
		printf("\n SAAVU LE");
	}
	struct node * temp = root;
	while(temp!=NULL)
	{
		printf("\n%d - ",temp->vertex);
		struct node * temp2;
		temp2 = temp->next;
		while(temp2!=NULL)
		{
			printf("%d-> ",temp2->vertex);
			temp2 = temp2->next;
		}
		printf("NULL");
		temp = temp -> nextvertex;
	}
}