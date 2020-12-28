//2 way linked list

#include <stdio.h>
#include <stdlib.h>

struct linked_list
{
    struct linked_list *previous;
    int num;
    struct linked_list *next;
};

typedef struct linked_list node;
void start(node* list);
void show(void);
void printing(node *list);
void revprinting(node *list);
void insertion(void);
void search(void);
int count(node *list);
void deletion(void);
node *head;
node *last;
int main()
{
    printf("Doubly Linked List...(Enter -999 to finish)\n");
    head=(node*)malloc(sizeof(node));
    head->previous=NULL;
    start(head);
    show();
    return 0;
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
        head->previous=NULL;
        p1=head;
    }
hi:
    printf("Enter the number: ");
    scanf("%d",&number);

    if(number!=-999)
    {
        newnode=(node*)malloc(sizeof(node));
        newnode->num=number;
        newnode->previous=p1;
        p1->next=newnode;
        p1=newnode;

        goto hi;
    }
    else
    {
        newnode->next=NULL;
        last=newnode;
    }
    return;
}
void show(void)
{
    int a;
    printf("\nEnter the action to be performed(0 to exit): ");
    printf("1. Print list.");
    printf("2. Insertion.");
    printf("3. Deletion.");
    printf("4. searching.");
    scanf("%d",&a);
    switch(a)
    {
        case 1:
        {
            int b;
            printf("Enter the option: 1. print forward 2. print reverse.");
            scanf("%d",&b);

            if(b==1)
                printing(head);
            else if(b==2)
                revprinting(last);
            else
                {
                    printf("\nInvalid Input.");
                }
                show();
                break;
        }
        case 2: insertion();
                show();
                break;
        case 3: deletion();
                show();
                break;
	case 4: search();
		show();
		break;
        case 0: exit(0);
        default:printf("Invalid Input");
                show();
                break;
        return;
    }
}
void printing(node *list)
{
        if(head==NULL)
        {
            printf("Empty list.");
            show();
            return;
        }
        else if(list->next!=NULL)
        {
            printf("->%d",list->num);
            printing(list->next);
        }
        printf("->%d",list->num);
        show();
        return;
}
void revprinting(node *list)
{
        if(last==NULL)
        {
            printf("Empty list.");
            show();
            return;
        }
        else if(list->previous!=NULL)
        {
            printf("->%d",list->num);
            revprinting(list->previous);
        }
        printf("->%d",list->num);

        show();
        return;
}
void insertion(void)
{
    int pos;
    node *new;
    new=(node *)malloc(sizeof(node));

    printf("\nEnter the value: ");
    scanf("%d",&new->num);

    printf("\nEnter the position: ");
    scanf("%d",&pos);

    if(pos==1)
    {
        new->next=head;
        head->previous=new;
        new->previous=NULL;
        head=new;
    }
    else if(pos>1&&pos<=count(head))
    {
        node* p1;
        p1=head;

        for(int i=2;i<pos;i++)
            p1=p1->next;

        new->next=p1->next;
        p1->next->previous=new;
        p1->next=new;
        new->previous=p1;
    }
    else if(pos==count(head)+1)
    {
        node* p1;
        p1=head;

        for(int i=2;i<pos;i++)
            p1=p1->next;

        new->next=NULL;
        p1->next=new;
        new->previous=p1;
        last=new;
    }
    else
        printf("\nInvalid input.");
    return;
}
int count(node *list)
{
    if(list->next==NULL)
        return 1;
    else
        return 1+count(list->next);
}
void deletion(void)
{
    int pos;
    node *p2;
    printf("Enter the position to be deleted: ");
    scanf("%d",&pos);
    if(pos==1)
    {
        p2=head->next;
        head->next->previous=NULL;
        free(head);
        head=p2;

    }
    else if(pos>1&&pos<count(head))
    {
        node* p1;
        p1=head;

        for(int i=2;i<pos;i++)
            p1=p1->next;

        p2=p1->next->next;
        p2->previous=p1;
        free(p1->next);
        p1->next=p2;
    }
    else if(pos==count(head))
    {
        node* p1;
        p1=head;

        for(int i=2;i<count(head);i++)
            p1=p1->next;

        free(p1->next);
        p1->next=NULL;
        last=p1;
    }

    else
        printf("\nInvalid input.");
    return;
}
void search(void)
{
    int number,some=-1;
    printf("Enter the number to be searched: ");
    scanf("%d",&number);

        node* p1;
        p1=head;

	if(number==head->num)
	{
		some=1;
		printf("The number %d is present at position: 1",number);
		return;
	}
	else
	{
		while(p1->next!=NULL)
		{
			p1=p1->next;
			if(number==p1->num)
        			{
					some=1;
					printf("\nThe number  %d is present at position: %d",number,count(head)-count(p1)+1);
					break;
				}
		}
	}
	if(some==-1)
		printf("Number not present in list.");

        return;
}

