//Singly linked list
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
void printing(node *list);
void insertion(void);
int count(node *list);
void deletion(void);
node *head;
int main()
{
    printf("Linked List...\n");
    head=(node*)malloc(sizeof(node));
    start(head);
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
void show(void)
{
    int a;
    printf("\nEnter the action to be performed(0 to exit): ");
    printf("1. Print list.");
    printf("2. Insertion.");
    printf("3. Deletion.");

    scanf("%d",&a);

    switch(a)
    {
        case 1: printing(head);
                show();
                break;
        case 2: insertion();
                show();
                break;
        case 3: deletion();
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

    if(list->num!=-999)
    {
        printf("->%d",list->num);
        printing(list->next);
    }
    else if(head->next==NULL)
    {
        printf("Empty list.");
    }

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
    else if(pos>1&&pos<=count(head))
    {
        node* p1;
        p1=head;

        for(int i=2;i<pos;i++)
            p1=p1->next;

        new->next=p1->next;
        p1->next=new;
    }
    else if(pos==count(head)+1)
    {
        node* p1;
        p1=head;

        for(int i=2;i<pos;i++)
            p1=p1->next;

        new->next=p1->next;
        p1->next=new;
    }
    else
        printf("\nInvalid input.");
    return;
}
int count(node *list)
{
    if(list->next==NULL)
        return 0;
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
        free(head);
        head=p2;

    }
    else if(pos>1&&pos<=count(head))
    {
        node* p1;
        p1=head;

        for(int i=2;i<pos;i++)
            p1=p1->next;

        p2=p1->next->next;
        free(p1->next);
        p1->next=p2;
    }
    else
        printf("\nInvalid input.");
    return;
}

