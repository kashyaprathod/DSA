#include<stdio.h>
#include<stdlib.h>
struct node{
    struct node *left;
    int data;
    struct node *right;
};
struct node *tree;
void createtree(struct node *);
struct node *insertelement(struct node *, int val);
struct node *deleteelement(struct node *, int val);
void preorder(struct node *);
void inorder(struct node *);
void postorder(struct node *);
int totalNodes(struct node *);
int externalNodes(struct node *);

int main(void){
    int option, val;
    struct node *ptr;
    do
    {
        printf("\nMain Menu\n");
        printf("1. Insert element in tree\n");
        printf("2. Delete element frmo tree\n");
        printf("3. Pre-Order Traversal\n");
        printf("4. Inorder Traversal\n");
        printf("5. Post-Order Traversal\n");
        printf("6. Total number of nodes\n");
        printf("7. Number of external nodes");
        printf("8. Exit\n");
        printf("Enter your choice :\n");
        scanf("%d" ,&option);
        switch (option)
        {
        case 1:
            printf("Enter element you want to insert: \n");
            scanf("%d", &val);
            tree = insertelement(tree, val);
            break;
        case 2:
            printf("Enter value you want to delete:\n");
            scanf("%d", &val);
            tree = deleteelement(tree, val);
            break;
        case 3:
            preorder(tree);
            break;
        case 4:
            inorder(tree);
            break;
        case 5:
            postorder(tree);
            break;
        case 6:
            printf("Total Number of nodes is: %d \n", totalNodes(tree));
            break;
        case 7:
            printf("Total Exteral Nodes are : %d\n", externalNodes(tree));
            break;
        case 8: 
            printf("Exiting program...\n");
            break;
        
        default:
            printf("Invalid Option choosen.\n");
            break;
        }
    } while (option != 8);
}

void createtree(struct node *tree){
    tree = NULL;
}

struct node *insertelement(struct node *tree, int val){
    struct node *ptr, *nodeptr, *parentptr;
    ptr = (struct node *)malloc(sizeof(struct node));
    ptr->data = val;
    ptr->left = NULL;
    ptr->right = NULL;
    if (tree == NULL)
    {
        tree = ptr;
        tree->left = NULL;
        tree->right = NULL;
    }
    else
    {
        parentptr = NULL;
        nodeptr = tree;
        while (nodeptr != NULL)
        {
            parentptr = nodeptr;
            if (val < nodeptr->data)
            {
                nodeptr = nodeptr->left;
            }
            else
            {
                nodeptr = nodeptr->right;
            }
        }
        if (val < parentptr->data)
        {
            parentptr->left = ptr;
        }else{
            parentptr->right = ptr;
        }
        
    }   
    return tree;
}

void preorder(struct node *tree){
    if (tree != NULL)
    {
        printf("%d ", tree->data);
        preorder(tree->left);
        preorder(tree->right);
    }    
}

void inorder(struct node *tree){
    if (tree != NULL)
    {
        inorder(tree->left);
        printf("%d ", tree->data);
        inorder(tree->right);
    }
    
}
void postorder(struct node *tree){
    if (tree != NULL)
    {
        postorder(tree->left);
        postorder(tree->right);
        printf("%d ", tree->data);
    }
}

struct node *deleteelement(struct node *tree, int val){
    struct node *ptr,*parent, *cur, *psuc, *suc;
    if (tree == NULL)
    {
        printf("Tree is empty\n");
        return tree;
    }
    cur = tree;
    parent = NULL;
    while (cur != NULL && val != cur->data)
    {
        parent = cur;
        cur = (val < cur->data) ? cur->left : cur->right;
    }
    if (cur == NULL)
    {
        printf("\nValue to be deleted is not present in the tree\n");
        return tree;
    }
    
    
    if(cur->left == NULL && cur->right == NULL){
        ptr = NULL;
        if(parent == NULL){
            printf("Value %d is deleted from tree\n", val);
            free(cur);
            tree = NULL;
            return tree;
        }
    }else if (cur->left == NULL)
    {
        ptr = cur->right;
    }else if (cur->right == NULL){
        ptr = cur->left;
    }else{
        psuc = cur;
        suc = cur->right;
        while (suc->left != NULL)
        {
            psuc = suc;
            suc = suc->left;
        }
        if (cur == psuc)
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
    if (parent == NULL)
    {
        tree = ptr;
    }
    else if(parent->left == cur)
    {
        parent->left = ptr;
    }else{
        parent->right = ptr;
    }
    printf("Value %d is deleted from the tree\n", val);
    free(cur);
    return tree;
}

int totalNodes(struct node *tree){
    if (tree == NULL)
    {
        return 0;
    }
    else
    {
        return (totalNodes(tree->left) + totalNodes(tree->right) + 1);
    }   
}

int externalNodes(struct node *tree){
    if (tree == NULL)
    {
        return 0;
    }
    else if(tree->left == NULL &&  tree->right == NULL)
    {
        return 1;
    }else{
        return(externalNodes(tree->left) + externalNodes(tree->right));
    }
}

