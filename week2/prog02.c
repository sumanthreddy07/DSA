//Circular linked list

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
void finishing(void);
void printing(void);
void insertion(void);
void deletion(void);
void search(void);
int count(node *list);
node *head;
int main()
{
    printf("Circular linked list\n");
    head=(node*)malloc(sizeof(node));
    start(head);
    finishing();
    show();
    return 0;
}
void start(node* list)
{
    printf("Enter the element(Type -999 to end): ");
    scanf("%d",&list->num);

    if(list->num==-999)
    {
        list->next=NULL;
    }
    else
    {
        list->next=(node*)malloc(sizeof(node));
        start(list->next);
    }
    return;
}
void finishing(void)
{
    node *p1;
    p1=head;

    while(p1->next->num!=-999)
        p1=p1->next;
    free(p1->next);
    p1->next=head;

}
void show(void)
{
    int a;
    printf("\nEnter the action to be performed(0 to exit): ");
    printf("1. Print list.");
    printf("2. Insertion.");
    printf("3. Deletion.");
    printf("4. Searching.");

    scanf("%d",&a);
    switch(a)
    {
        case 1: printing();
                show();
                break;
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
void printing(void)
{

    node *p1;
    p1=head;

    if(head->num==-999)
    {
        printf("Empty list.");
    }
    else
    {
        printf("->%d",p1->num);
        p1=p1->next;
    }
    while(p1->next!=head->next)
    {
        printf("->%d",p1->num);
        p1=p1->next;
    }

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
        head=new;
    }
    else
    {
        node* p1;
        p1=head;

        for(int i=2;i<pos;i++)
            p1=p1->next;

        new->next=p1->next;
        p1->next=new;
    }
    return;
}
void deletion(void)
{
    int pos;
    node *p2;
    printf("Enter the position to be deleted: ");
    scanf("%d",&pos);
    if(pos==1)
    {
        node* p1;
        p1=head;
        pos=1+count(head);

        for(int i=2;i<pos;i++)
            p1=p1->next;

        p1->next=head->next;
        head=p1->next;
    }
    else
    {
        node* p1;
        p1=head;

        for(int i=2;i<pos;i++)
            p1=p1->next;

        p2=p1->next->next;
        free(p1->next);
        p1->next=p2;
    }
    return;
}
int count(node *list)
{
    if(list->next->next==head)
        return 2;
    else
        return 1+count(list->next);
}
void search(void)
{
    int number,some=-1,sum=2;
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
                while(p1->next!=head)
                {
                        p1=p1->next;
                        if(number==p1->num)
                                {
                                        some=1;
					printf("\nThe number  %d is present at position: %d",number,sum);
                                        break;
                                }
			sum++;
                }
        }
        if(some==-1)
                printf("Number not present in list.");

        return;
}

