//To create a loop and breaking it in singly linked list
#include<stdio.h>
#include<stdlib.h>

struct linked_list
{
    int num;
    struct linked_list *next;
};
typedef struct linked_list node;
void start(node* list);
void show(void);
void looping(void);
void printing(node *list);
void checkforloop(void);
int count(node *list);
void breaking(void);
node *head,*ptr;
int sum;
int main()
{
    printf("Linked List...\n");
    head=(node*)malloc(sizeof(node));
    start(head);
    sum=count(head);
    show();
    return 0;
}

void show(void)
{
    int a;
    printf("\nEnter the action to be performed(0 to exit): ");
    printf("1. Print list.");
    printf("2. Looping.");
    printf("3. Check for loop.");
    printf("4. break.");
    scanf("%d",&a);

    switch(a)
    {
        case 1: printing(head);
		show();
                break;
	case 2: looping();
		show();
		break;
	case 3: checkforloop();
		show();
		break;
	case 4: breaking();
		show();
		break;
        case 0: exit(0);
        default:printf("Invalid Input");
                show();
                break;
        return;
    }
}
void printing(node* list)
{

    if(head==NULL)
    {
        printf("Empty list.");
	return;
    }
    else if(list->next!=NULL)
    {
        printf("->%d",list->num);
        printing(list->next);
	return;
    }
	printf("->%d",list->num);

    return;
}
int count(node *list)
{
    if(list->next==NULL)
        return 1;
    else
        return 1+count(list->next);
}

void looping(void)
{
	node *p2,*p3;
	p2=head;
	p3=head;
	int pos;
	printf("Enter the position where looping must take place: ");
	scanf("%d",&pos);

	for(int i=2;i<pos;i++)
                p2=p2->next;
	for(int j=2;j<sum;j++)
		p3=p3->next;

	if(pos==1)
		{
			p3->next=head;
			printf("done");
		}
	else if(pos>1&&pos<=sum)
		{
			p3->next=p2;
			printf("done");
		}
	else
	{
		printf("Invalid input.");
		return;
	}
	printf("Loop created");
	return;

}
void start(node* list)
{
    node* p1;
    node* newnode;
    int number;
    printf("Enter the number: ");
    scanf("%d",&number);

    if(number==-999)
    {
        free(head);
        head=NULL;
        return;
    }
    else
    {
        head->num=number;
        p1=head;
    }
hi:
    printf("Enter the number: ");
    scanf("%d",&number);

    if(number!=-999)
    {
        newnode=(node*)malloc(sizeof(node));
        newnode->num=number;
        p1->next=newnode;
        p1=newnode;

        goto hi;
    }
    else
    {
        ptr=p1->next;
	p1->next=NULL;
    }
    return;
}
void checkforloop(void)
{
	int flag=0;
	node *p1,*p2;
	p1=head;
	p2=head;

        while((p1->next!=NULL&&p2->next!=NULL&&p2->next->next!=NULL))
	{
		p1=p1->next;
		p2=p2->next->next;
		flag++;
		if(p1==p2)
		break;

	}

	if(p1==p2)
		printf("loop is present");
	else
		printf("loop is not present.");
	return;
}
void breaking(void)
{
	node *p3;
	p3=head;
        for(int j=2;j<sum;j++)
                p3=p3->next;
                        p3->next=NULL;
                        printf("done");
}

