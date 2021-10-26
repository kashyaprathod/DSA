#include<stdio.h>
#define MAX 10
int adj[MAX][MAX];
//function declaration
void creategraph(int size);
void displaygraph(int size);
void insertedge(int o, int d, int n);
void deleteedge(int o, int d, int n);
//main function
int main(){
    int option, size, o, d;
    do
    {
        printf("\nMain Menu \n");
        printf("1. Create a graph \n");
        printf("2. Insert an edge \n");
        printf("3. Delete an edge \n");
        printf("4. Display graph \n");
        printf("5. Exit\n");
        printf("Enter your option: \n");
        scanf("%d", &option);
        switch (option)
        {
        case 1:
            printf("Enter the number of nodes in the graph: \n");
            scanf("%d", &size);
            creategraph(size);
            break;
        case 2:
            printf("Enter an edge to be inserted: \n");
            scanf("%d %d", &o, &d);
            insertedge(o, d, size);
            break;
        case 3:
            printf("Enter an edge to be deleted: \n");
            scanf("%d %d", &o, &d);
            deleteedge(o, d, size);
            break;
        case 4: 
            displaygraph(size);
            break;
        
        default:
            printf("Invalid Option");
            break;
        }
    } while (option != 5);
}
//create graph function
void creategraph(int size){
    int i,j;
    printf("Enter the adjacency matrix: \n");
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
        {
            scanf("%d", &adj[i][j]);
        }
        
    }
}
void insertedge(int o, int d, int n){
    if (o<0 || o>=n)
    {
        printf("\nOrigin vertex does not exist");
    }
    else if (d<0 || d>=n)
    {
        printf("\ndestination vertex does not exist");
    }
    else if (adj[o][d] == 0)
    {
        adj[o][d] = 1;
    }else{
        printf("\nInsertion is not possible");
    }
    
}
void deleteedge(int o, int d, int n){
    if (o<0 || o>=n)
    {
        printf("\nOrigin vertex does not exist");
    }
    else if (d<0 || d>=n)
    {
        printf("\ndestination vertex does not exist");
    }
    else if (adj[o][d] == 0)
    {
        adj[o][d] = 1;
    }else{
        printf("\nDeletion is not possible");
    }
}
void displaygraph(int size){
    int i,j;
    printf("\nGraph wtih adjacency matrix representation: \n");
    printf("\t");
    for (int i = 0; i < size; i++)
    {
        printf("%c \t", i+65);
    }
    for (int i = 0; i < size; i++)
    {
        printf("\n");
        printf("%c\t", i+65);
        for (int j = 0; j < size; j++)
        {
            printf("%d \t", adj[i][j]);
        }   
    }
}

