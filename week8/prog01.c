#include<stdio.h>
#include<stdlib.h>

struct node
{
	int data;
	struct node* left;
	struct node* right;
};
void show(struct node *ptr);
void insert(struct node* ptr,int num);
void preorder(struct node* ptr);
void inorder(struct node* ptr);
void postorder(struct node* ptr);
void delete(struct node* ptr,int value,struct node *temp);
int main()
{
	struct node *head;
	head=(struct node*)malloc(sizeof(struct node));
	head->data=-999;
	head->left=NULL;
	head->right=NULL;
	show(head);


}

void show(struct node* ptr)
{
	int val;
	printf("\n 1.Insert\n 2.delete\n 3.Display\n 0.Exit\n");
	scanf("%d",&val);

	switch(val)
	{
		case 1:         
       			printf("Enter the number: ");
        		int num;
			scanf("%d",&num);
			insert(ptr,num);
			show(ptr);
			break;
		case 2:	printf("Enter the value to be deleted: ");
			int value,flag;
			scanf("%d",&value);
			delete(ptr,value,ptr);

			show(ptr);
			break;
		case 3: printf("1.Preorder 2.Inorder 3.Postorder");
			int x;
			scanf("%d",&x);
			switch(x)
			{
				case 1: preorder(ptr);
				break;
				case 2: inorder(ptr);
				break;
				case 3: postorder(ptr);
				break;
			}
			show(ptr);
			break;
		case 0:	break;
		defalut:printf("\n invalid input.");
			show(ptr);
			break;
	}
	return;
}
void insert(struct node *ptr,int num)
{

	if(ptr->data!=-999)
	{    
	int a;	
	printf("Node is filled: choose \n1.to insert on left \n2.to insert on right");
        scanf("%d",&a);
	switch(a)
        {
                case 1:
			if(ptr->left==NULL)
			{
		                struct node *newnode;
                		newnode=(struct node*)malloc(sizeof(struct node));
		                newnode->data=num;
        		        newnode->left=NULL;
                		newnode->right=NULL;
                		ptr->left=newnode;
				printf("Inserted\n");
			}
			else
				insert(ptr->left,num);
                        break;
                case 2:
			if(ptr->right==NULL)
                        {
                                struct node *newnode;
                                newnode=(struct node*)malloc(sizeof(struct node));
                                newnode->data=num;
                                newnode->left=NULL;
                                newnode->right=NULL;
                                ptr->right=newnode;
				printf("Inserted\n");
                        }
                        else
				insert(ptr->right,num);
                        break;
     	}
	}
	else if(ptr->data==-999)
	{
		ptr->data=num;
		ptr->left=NULL;
		ptr->right=NULL;
	}
	return;
}
void preorder(struct node *ptr)
{
	if(ptr==NULL)
	return;
	else
	{
		printf(" %d ",ptr->data);
		preorder(ptr->left);
		preorder(ptr->right);
	}
}
void inorder(struct node *ptr)
{
        if(ptr==NULL)
        return;
        else
        {
                inorder(ptr->left);
                printf(" %d ",ptr->data);
                inorder(ptr->right);
        }
}
void postorder(struct node *ptr)
{
        if(ptr==NULL)
        return;
        else
        {
                postorder(ptr->left);
                postorder(ptr->right);
		printf(" %d ",ptr->data);
        }
}
void delete(struct node* ptr,int value,struct node* temp)
{
	if(ptr!=NULL)
	{
	if(ptr->data!=value)
		{
		delete(ptr->left,value,ptr);
		delete(ptr->right,value,ptr);
		}
	else
		{
		if(temp->left==ptr)
		temp->left=NULL;
		else if(temp->right==ptr)
		temp->right=NULL;
		else if(temp==ptr)
		free(ptr);
		
		printf("Deleted");
		}
	}
	return;
}
