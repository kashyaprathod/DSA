#include <stdio.h> 
#define MAX 5 
//-----BFS FUNCTION------
void breadth_first_search(int adj[][MAX], int visited[], int start) { 
    int queue[MAX], rear = -1, front = -1, i, k; 
    for (k = 0; k < MAX; k++) 
        visited[k] = 0; 

    queue[++rear] = start; 
    ++front; 
    visited[start] = 1; 

    while (rear >= front) {
        start = queue[front++]; 
        printf("%c-", start + 65); 
        
        for (i = 0; i < MAX; i++) {
            
            if (adj[start][i] && visited[i] == 0) {
                queue[++rear] = i; 
                visited[i] = 1; 
            } 
        } 
    }    
} 
//-----DFS FUNCTION------
void depth_first_search(int adj[][MAX], int visited[], int start) { 
    int stack[MAX]; 
    int top = -1, i, k; 
    
    for (k = 0; k < MAX; k++) { 
        visited[k] = 0; 
    } 
    stack[++top] = start; 
    visited[start] = 1;
    
    while (top != -1) { 
        start = stack[top--]; 
        printf("%c-", start + 65); 
        
        for (i = 0; i < MAX; i++) { 
            if (adj[start][i] && visited[i] == 0) { 
                stack[++top] = i; 
                visited[i] = 1; 
                break; 
            } 
        } 
    } 
} 
//-----main function------
int main() { 
    int visited[MAX] = {0}; 
    int adj[MAX][MAX], i, j; 
    int option, size; 
    
    do { 
        printf("\n 1. Enter values in graph"); 
        printf("\n 2. BFS Traversal "); 
        printf("\n 3. DFS Traversal "); 
        printf("\n 4. EXIT "); 
        printf("\n\n Enter your choice : "); 
        scanf("%d", &option); 
        
        switch (option) { 
            case 1: 
                printf("\n Enter the adjacency matrix: "); 
                
                for (i = 0; i < MAX; i++) { 
                    for (j = 0; j < MAX; j++) 
                        scanf("%d", &adj[i][j]); 
                } 
                break; 
            
            case 2: 
                printf("BFS Traversal: "); 
                breadth_first_search(adj, visited, 0); 
                break; 
            
            case 3: 
                printf("DFS Traversal: "); 
                depth_first_search(adj, visited, 0); 
                break; 
        }
    } while (option != 4); 
    
    return 0; 
}