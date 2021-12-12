#include <stdio.h>
#define MAX 10
int hashtbl[MAX];
int a[MAX];

// main function
int main()
{
    int i, j, m, hashval;

    // load the array from user
    printf("\n Enter size of array : ");
    scanf("%d", &m);
    printf("\n Enter the values in array : ");
    for (i = 0; i < m; i++)
        scanf("%d", &a[i]);

    // initialise the hash table with values 999
    for (i = 0; i < m; i++)
    {
        hashtbl[i] = 999;
    }

    // apply hashing with linear probing
    for (i = 0; i < m; i++)
    {
        j = 0;
        do
        {
            hashval = (((a[i] % m) + j) % m);
            j++;
        } while (hashtbl[hashval] != 999);
        hashtbl[hashval] = a[i];
    }

    printf("\n");
    for (j = 0; j < m; j++)
    {
        printf("Element at location %d : %d\n", j, hashtbl[j]);
    }
    printf("\n");
    for (j = 0; j < m; j++)
    {
        printf(" %d ", hashtbl[j]);
    }
    return 0;
}