#include <stdio.h>
#include<stdlib.h>
//#include <conio.h>
//#include <malloc.h>
struct node
{
    int data;
    struct node *left;
    struct node *right;
};
///////////
struct node *tree;
void create_tree(struct node *);
struct node *insertElement(struct node *, int);
void preorderTraversal(struct node *);
void inorderTraversal(struct node *);
void postorderTraversal(struct node *);
struct node *deleteElement(struct node *,int);
int totalNodes(struct node *);
int totalExternalNodes(struct node *);
int Height(struct node *);
struct node *deleteTree(struct node *);
//////////
int main()
{
    int option,val;
    struct node *ptr;
    create_tree(tree);
    do
    {
        printf("\n *MAIN MENU \n");
        printf("\n 1. Insert Element");
        printf("\n 2. Preorder Traversal");
        printf("\n 3. Inorder Traversal");
        printf("\n 4. Postorder Traversal");
        printf("\n 5. Delete an element ");
        printf("\n 6. Count the total number of nodes ");
        printf("\n 7. Count the total number of external nodes ");
        printf("\n 8. Delete the tree ");
        printf("\n 9. Exit ");
        printf("\n\n Enter your option : ");
        scanf("%d", &option);
        switch(option)
        {
            case 1:
                printf("\n Enter the value of the new node :\n ");
                scanf("%d", &val);
                tree = insertElement(tree, val);
                break;
            case 2:
                printf("\n The elements of the tree are:\n");
                preorderTraversal(tree);
                break;
            case 3:
                printf("\n The elements of the tree are:\n");
                inorderTraversal(tree);
                break;
            case 4:
                printf("\n The elements of the tree are:\n");
                postorderTraversal(tree);
                break;
            case 5:
                printf("\n Enter the element to be deleted :\n ");
                scanf("%d", &val);
                tree = deleteElement(tree, val);
                break;
            case 6:
                printf("\n Total number of nodes =%d",totalNodes(tree));
                break;
            case 7:
                printf("\n Total number of external nodes = %d",totalExternalNodes(tree));
                break;
            case 8:
                tree =deleteTree(tree);
                break;
        }
    }while(option!=9);
    return 0;
}
void create_tree(struct node *tree)
{
    tree = NULL;
}
struct node *insertElement(struct node *tree,int val)
{
    struct node *ptr, *nodeptr, *parentptr;
    ptr = (struct node*)malloc(sizeof(struct node));
    ptr->data = val;
    ptr->left = NULL;
    ptr->right = NULL;
    if(tree==NULL)
    {
        tree=ptr;
        tree->left=NULL;
        tree->right=NULL;
    }
    else
    {
        parentptr = NULL;
        nodeptr=tree;
        while(nodeptr!=NULL)
        {
            parentptr=nodeptr;
            if(val<nodeptr->data)
            nodeptr=nodeptr->left;
            else
            nodeptr=nodeptr->right;
        }
        if(val<parentptr->data)
            parentptr->left = ptr;
        else
            parentptr->right = ptr;
    }
    return tree;
}
            /////////////
void preorderTraversal(struct node *tree) //DLR
{
    if(tree != NULL)
    {
        printf("%d\t", tree->data);
        preorderTraversal(tree->left); //recursive call to the same function but input is diff .
        preorderTraversal(tree->right);
    }
}
////////////
void inorderTraversal(struct node *tree) //lDR
{
    if(tree != NULL)
    {
        inorderTraversal(tree->left);
        printf("%d\t", tree->data);
        inorderTraversal(tree->right);
    }
}
///////////
void postorderTraversal(struct node *tree) //LRD
{
    if(tree != NULL)
    {
        postorderTraversal(tree->left);
        postorderTraversal(tree->right);
        printf("%d\t", tree->data);
    }
}
///////////
struct node *deleteElement(struct node *tree, int val)
{
    struct node *cur,*parent,*suc,*psuc,*ptr;
    if(tree == NULL)
    {
        printf("\n The tree is empty");
        return(tree);
    }
    cur = tree;
    parent = NULL;
    while(cur!=NULL && val!=cur->data)
    {
        parent = cur;
        cur = (val<cur->data)? cur->left:cur->right;
    }
    if(cur == NULL)
    {
        printf("\n The value to be inserted is not present in the tree");
        return(tree);
    }
    if(cur->left == NULL && cur->right == NULL)
    { 
        ptr = NULL;
        if(parent == NULL)
        {
            printf("Value %d is deleted",cur->data);
            free(cur);
            tree = NULL;
            return tree;
        }
    }
    else if(cur->left == NULL)
        ptr = cur->right;
    else if(cur->right == NULL)
        ptr = cur->left;
    else
    {
        psuc = cur;
        suc = cur->right;
        while(suc->left != NULL)
        {
            psuc = suc;
            suc = suc->left;
        }
        if(cur == psuc)
        {
            suc->left = cur->left;
        }
        else
        {
            suc->left = cur->left;
            psuc->left = suc->right;
            suc->right = cur->right;
        }
        ptr = suc;
    }
        if(parent == NULL)
            tree = ptr;
        else if(parent->left == cur)
            parent->left = ptr;
        else
            parent->right = ptr;
        printf("Value %d is deleted",cur->data);
        free(cur);
        return tree;
}
int totalNodes(struct node *tree)
{
    if(tree == NULL)
        return 0;
    else
        return(totalNodes(tree->left)+totalNodes(tree->right)+1);
}
int totalExternalNodes(struct node *tree)
{
    if(tree == NULL)
        return 0;
    else if((tree->left == NULL)&&(tree->right == NULL))
        return 1;
    else
        return (totalExternalNodes(tree->left))+(totalExternalNodes(tree->right));
}
struct node *deleteTree(struct node *tree)
{
    if(tree != NULL)
    {
        deleteTree(tree->left);
        deleteTree(tree->right);
        free(tree);
    }
}             