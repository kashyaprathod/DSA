#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node *next;
};
struct node *start = NULL;
struct node *create_cll(struct node *start);
struct node *display(struct node *start);
struct node *insert_beg(struct node *start);
struct node *insert_end(struct node *start);
struct node *delete_beg(struct node *start);
struct node *delete_end(struct node *start);

int main(void){
    printf("Implementing circular linked list.\n");
    int ch;
    do
    {
        printf("1. craete Linked list\n");
        printf("2. Add node at beginning\n");
        printf("3. Add Node at end\n");
        printf("4. Add node after a node\n");
        printf("5. Delete node from beginning\n");
        printf("6. Delete node from end\n");
        printf("7. Display Ciruclar Linked List\n");
        printf("8. Exit\n");
        printf("Enter your choice: \n");
        scanf("%d", &ch);
        switch (ch)
        {
        case 1:
            start = create_cll(start);
            break;
        case 2:
            start = insert_beg(start);
            break;
        case 3:
            start = insert_end(start);
        case 5:
            start  = delete_beg(start);
            break;
        case 6:
            start = delete_end(start);
        case 7:
            start = display(start);
            break;
        case 8:
            printf("Exiting Program\n");
        default:
            break;
        }
    } while (ch != 8);
}

struct node *create_cll(struct node *start){
    struct node *new_node, *ptr;
    int num;
    
    printf("Enter -1 to end\n");
    printf("Enter Value: \n");
    scanf("%d", &num);
    
    while (num != -1)
    {
        new_node = (struct node *)malloc(sizeof(struct node));
        new_node->data = num;
         if (start == NULL)
        {
            new_node->next = new_node;
            start = new_node;
        }
        else
        {
            ptr = start;
            while (ptr->next != start)
            {
                ptr = ptr->next;
            }
            ptr->next = new_node;
            new_node->next = start;
        }
        printf("Enter the data: \n");
        scanf("%d", &num);
    }
    return start;
}

struct node *display(struct node *start){
    struct node *ptr;
    ptr = start;
    while (ptr->next != start)
    {
        printf("%d\t", ptr->data);
        ptr = ptr->next;
    }
    printf("%d", ptr->data);
    printf("\n");
    return start;
}

struct node *insert_beg(struct node *start){
    struct node *new_node, *ptr;
    ptr = start;
    new_node = (struct node *)malloc(sizeof(struct node));
    int num;
    printf("Enter number: \n");
    scanf("%d", &num);
    new_node->data = num;
    while (ptr->next != start)
    {
        ptr = ptr->next;
    }
    ptr->next = new_node;
    new_node->next = start;
    start = new_node;
    return start;    
}

struct node *insert_end(struct node *start){
    struct node *new_node, *ptr;
    ptr = start;
    new_node = (struct node *)malloc(sizeof(struct node));
    int num;
    printf("Enter Value: \n");
    scanf("%d", &num);
    new_node->data = num;
    while (ptr->next != start)
    {
        ptr = ptr->next;
    }
    ptr->next = new_node;
    new_node->next = start;
    return start;
}

struct node *delete_beg(struct node *start){
    struct node *ptr;
    ptr = start;
    while (ptr->next != start)
    {
        ptr = ptr->next;
    }
    ptr->next = start->next;
    free(start);
    start = ptr->next;
    return start;    
}

struct node *delete_end(struct node *start){
    struct node *ptr, *preptr;
    ptr = start;
    while (ptr->next != start)
    {
        preptr = ptr;
        ptr = ptr->next;
    }
    preptr->next = start;
    free(ptr);
    return start;
}