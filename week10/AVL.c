//AVL TREE
#include <stdio.h>
#include <stdlib.h>

struct AVLnode
{
    struct AVLnode* left;
    int data;
    struct AVLnode* right;
    int height;
};
int Height(struct AVLnode* root)
{
    if(!root)
        return-1;
    else
        return root->height;
}
int max(int a, int b)
{
	if(a>b)
	return a;
	else
	return b;
}
struct AVLnode* singlerotleft(struct AVLnode*X)
{
    struct AVLnode *W=X->left;
    X->left=W->right;
    W->right=X;
    X->height=max(Height(X->left),Height(X->right))+1;
    W->height=max(Height(W->left),Height(W->right))+1;
    return W;
}
struct AVLnode* singlerotright(struct AVLnode*W)
{
    struct AVLnode *X=W->right;
    W->right=X->left;
    X->left=W;
    X->height=max(Height(X->left),Height(X->right))+1;
    W->height=max(Height(W->left),Height(W->right))+1;
    return X;
}
struct AVLnode*doublerotleft(struct AVLnode *Z)
{
    Z->left=singlerotright(Z->left);
    return singlerotleft(Z);
}
struct AVLnode* doublerotright(struct AVLnode *Z)
{
    Z->right=singlerotleft(Z->right);
    return singlerotright(Z);
}
struct AVLnode *Insert(struct AVLnode *root,int data)
{
    if(!root)
    {
        root=(struct AVLnode*)malloc(sizeof(struct AVLnode*));
        if(!root)
        {
            printf("Mem error");return NULL;
        }
        else
        {
            root->data;
        root->height=0;
        root->left=root->right=NULL;
        }
    }
    else if(data<root->data)
    {
        root->left=Insert(root->left,data);
        if(Height(root->left)-Height(root->right)==2)
        {
            if(data<root->left->data)
                root=singlerotleft(root);
            else
                root=doublerotleft(root);
        }
    }
    else if(data>root->data)
    {
        root->right=Insert(root->right,data);
        if(Height(root->right)- Height(root->left)==2)
        {
            if(data<root->right->data)
                root=singlerotright(root);
            else
                root=doublerotright(root);
        }
    }
    root->height=max(Height(root->left),Height(root->right))+1;
    return root;
}
void show(struct AVLnode* root)
{
    int a;
    printf("Enter the choice: 1.insert 2.delete");
    switch(a)
    {
        case 1: printf("\nEnter no. of elements:");
                    int n,x;
					scanf("%d",&n);
					printf("\nEnter tree data:");
					root=NULL;
					for(i=0;i<n;i++)
					{
						scanf("%d",&x);
						root=Insert(root,x);
					}
					break;

			case 2: printf("\nEnter a data:");
                    int data;
					scanf("%d",&data);
					root=insert(root,data);
					break;

			case 3: printf("\nEnter a data:");
					int key;
					scanf("%d",&key);
					root=Delete(root,key);
					break;

			case 4: printf("\nPreorder sequence:\n");
					preorder(root);
					printf("\n\nInorder sequence:\n");
					inorder(root);
					printf("\n");
					break;

    }
}
struct AVLnode* Delete(struct AVLnode* root, int key)
{
    if (root == NULL)
        return root;

    if ( key < root->data )
        root->left = Delete(root->left, key);

    else if( key > root->data )
        root->right = Delete(root->right, key);

    else
    {
        // node with only one child or no child
        if( (root->left == NULL) || (root->right == NULL) )
        {
            struct AVLnode *temp = root->left ? root->left :
                                             root->right;

            // No child case
            if (temp == NULL)
            {
                temp = root;
                root = NULL;
            }
            else // One child case
             *root = *temp; // Copy the contents of
                            // the non-empty child
            free(temp);
        }
        else
        {
            struct AVLnode* temp = minValueNode(root->right);

            root->data = temp->data;

            root->right = Delete(root->right, temp->data);
        }
    }

    // If the tree had only one node then return
    if (root == NULL)
      return root;

    root->height = 1 + max(height(root->left),
                           height(root->right));

											    // check whether this node became unbalanced)
    int balance = getBalance(root);

										    // If this node becomes unbalanced, then there are 4 cases

    // Left Left Case
    if (balance > 1 && getBalance(root->left) >= 0)
        return singlerotright(root);

    // Left Right Case
    if (balance > 1 && getBalance(root->left) < 0)
    {
        return doublerotright(root);
    }

    // Right Right Case
    if (balance < -1 && getBalance(root->right) <= 0)
        return singlerotleft(root);

    if (balance < -1 && getBalance(root->right) > 0)
    {
        return doublerotleft(root);
    }

    return root;
}
struct AVLnode * minValueNode(struct AVLnode* node)
{
    struct AVLnode* current = node;

    /* loop down to find the leftmost leaf */
    while (current->left != NULL)
        current = current->left;

    return current;
}
int getBalance(struct AVLnode *N)
{
    if (N == NULL)
        return 0;
    return height(N->left) - height(N->right);
}
void preorder(node *T)
{
	if(T!=NULL)
	{
		printf("%d(Bf=%d)",T->data,BF(T));
		preorder(T->left);
		preorder(T->right);
	}
}

void inorder(node *T)
{
	if(T!=NULL)
	{
		inorder(T->left);
		printf("%d(Bf=%d)",T->data,BF(T));
		inorder(T->right);
	}
}
int main()
{
    struct AVLnode* head;
    show(head);

    return 0;
}
