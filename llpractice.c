#include<stdio.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node *next;
};
struct node *start = NULL;

struct node *createll(struct node *);
struct node *display(struct node *);
struct node *addstart(struct node *);
struct node *insert_before(struct node *);
struct node *insert_after(struct node *);
struct node *addend(struct node *);
struct node *search(struct node *);
struct node *delete_last(struct node *);
struct node *delete_first(struct node *);
struct node *delete_given_node(struct node *);
struct node *delete_after(struct node *);

struct node *createll(struct node *start){
    struct node *new_node, *ptr;
    int num;
    printf("Enter -1 to exit\n");
    printf("Enter no to be entered : \n");
    scanf("%d", &num);
    while (num != -1)
    {
        new_node = (struct node *)malloc(sizeof(struct node));
        new_node->data = num;
        if (start==NULL)
        {
            new_node->next = NULL;
            start = new_node;
        }else{
            ptr = start;
            while (ptr->next != NULL)
            {
                ptr = ptr->next;
            }
            ptr->next = new_node;
            new_node->next = NULL;
        }
        printf("Enter the no to be entered : \n");
        scanf("%d", &num);
    }
    return start;   
}

struct node *display(struct node *start){
    struct node *ptr;
    ptr = start;
    while (ptr != NULL)
    {
        printf("%d\t", ptr->data);
        ptr = ptr->next;
    }
    return start;
}

struct node *addstart(struct node *start){
    struct node *new_node;
    new_node = (struct node*)malloc(sizeof(struct node));
    int num;
    printf("Enter number to be entered: \n");
    scanf("%d", &num);
    new_node ->data = num;
    new_node ->next = start;
    start = new_node;
    return start;
}

struct node *insert_before(struct node *start){
    struct node *new_node,*ptr,*preptr;
    int num,val;
    printf("Enter node you want to insert: \n");
    scanf("%d", &num);
    printf("Enter value before which you want to insert: \n");
    scanf("%d", &val);
    new_node = (struct node *)malloc(sizeof(struct node));
    new_node->data = num;
    ptr=start;
    //preptr=start;
    while (ptr->data != val)
    {
        preptr = ptr;
        ptr = ptr ->next;
    }
    preptr->next = new_node;
    new_node->next = ptr;
    return start;
}

struct node *insert_after(struct node *start){
    struct node *new_node,*preptr,*ptr;
    int num, val;
    printf("Enter node you want to insert : \n");
    scanf("%d", &num);
    printf("Enter value after which you want to insert : \n");
    scanf("%d", &val);
    new_node = (struct node *)malloc(sizeof(struct node));
    new_node->data = num;
    ptr = start;
    preptr = ptr;
    while (preptr->data != val)
    {
        preptr = ptr;
        ptr = ptr->next;
    }
    preptr->next = new_node;
    new_node->next = ptr;
    return start;
}

struct node *addend(struct node *start){
    struct node *new_node, *ptr;
    int num;
    printf("Enter node you want to insert : \n");
    scanf("%d", &num);
    new_node = (struct node *)malloc(sizeof(struct node));
    new_node->data = num;
    ptr = start;
    while (ptr->next != NULL)
    {
        ptr = ptr->next;
    }
    new_node->next = NULL;
    ptr->next = new_node;
    return start;
}

struct node *search(struct node *start){
    struct node *ptr;
    int num, flag=0;
    printf("Enter node you want to search for : \n");
    scanf("%d", &num);
    ptr = start;
    while (ptr->next != NULL)
    {
        if (ptr->data == num)
        {
            flag++;
            break;
        }
        ptr = ptr->next;
    }
    if (flag != 0)
    {
        printf("Node is found in the list\n");
    }
    else
    {
        printf("Node not found in list\n");
    }
    
    return start;
}

struct node *delete_last(struct node *start){
    struct node *ptr, *preptr;
    ptr = start;
    while (ptr->next != NULL)
    {
        preptr = ptr;
        ptr = ptr->next;
    }
    preptr->next = NULL;
    free(ptr);
    return start;
}
struct node *delete_first(struct node *start){
    struct node *ptr;
    ptr = start;
    ptr = ptr->next;
    start = ptr;
    return start;
}
struct node *delete_given_node(struct node *start){
    struct node *ptr, *preptr;
    int num;
    printf("Enter node you want to delete: \n");
    scanf("%d", &num);
    ptr = start;
    while (ptr->data != num)
    {
        preptr = ptr;
        ptr = ptr->next;
    }
    ptr = ptr->next;
    preptr->next = ptr;
    return start;
}
struct node *delete_after(struct node *start){
    struct node *ptr, *preptr;
    int num;
    printf("Enter node after which you want to delete: \n");
    scanf("%d", &num);
    ptr = start;
    while (ptr->data != num)
    {
        preptr = ptr;
        ptr = ptr->next;
    }
    ptr = ptr->next; 
    
}
int main(){
    int ch;
    do
    {
        printf("\n------------MENU-------------\n");
        printf("1: Create a linked list\n");
        printf("2: Display linked list\n");
        printf("3: Add node at beginning of list\n");
        printf("4: Enter node before a given node\n");
        printf("5: Enter node after a given node\n");
        printf("6: Add node at the end of list\n");
        printf("7: Search a node in the list\n");
        printf("8: Delete last node of list\n");
        printf("9: Delete first node of list.\n");
        printf("10: Delete given node from the list: \n");
        printf("11: Exit\n");
        printf("Enter your choice: \n");
        scanf("%d", &ch);
        switch (ch)
        {
        case 1:
            start = createll(start);
            break;
        case 2:
            start = display(start);
            break;
        case 3:
            start = addstart(start);
            break;
        case 4:
            start = insert_before(start);
            break;
        case 5:
            start = insert_after(start);
            break;
        case 6:
            start = addend(start);
            break;
        case 7:
            start = search(start);
            break;
        case 8:
            start = delete_last(start);
            break;
        case 9:
            start = delete_first(start);
            break;
        case 10: 
            start = delete_given_node(start);
            break;
        case 11:
            printf("Exiting program\n");
            break;
        default:
            printf("Invalid Chocie");
        }
    } while (ch != 11);
}