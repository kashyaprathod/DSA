#include <stdio.h>
#define MAX 10
int A[MAX];

void create_array(int arr[],int n);
void insertion_sort(int arr[], int n);
void quick_sort(int a[],int beg,int end);
void display_array(int arr[],int n);
int partition(int a[], int beg, int end);

int main()
{
int option, size;
do
{
printf("\n\n ***MAIN MENU** \n");
printf("\n 1. Enter values in array");
printf("\n 2. Insertion sort ");
printf("\n 3. Quick sort ");
printf("\n 4. Display array");
printf("\n 5. Exit ");
printf("\n\n Enter your option : ");
scanf("%d", &option);
switch(option)
{
case 1:
	printf("\n Enter the array size : ");
	scanf("%d", &size);
	create_array(A,size);
	break;
case 2:
	insertion_sort(A,size);
	printf("\n\nThe array is sorted successfully\n");
	break;
case 3:
	quick_sort(A,0,size-1);
	printf("\n\nThe array is sorted successfully\n");
	break;
case 4:
	display_array(A,size);
	break;
}
}while(option!=5);
return 0;
}

void create_array(int arr[],int n)
{
	int i;
	printf("\nEnter values to be sorted : ");
	for(i=0;i<n;i++)
	{
		scanf("%d",&arr[i]);
	}
}


void insertion_sort(int arr[], int n)
{
int i, j, temp;
	for(i=1;i<n;i++)
	{
		temp= arr[i];
		j= i-1;
		while((temp < arr[j]) && (j>=0))
		{
			arr[j+1]=arr[j];
			j--;
		}
		arr[j+1] = temp;
		printf("\nPass %d : ",i);
		display_array(arr,n);
	}
}

void quick_sort(int a[],int beg,int end)
{
	int size = end+1;
	int loc;
	static int i=1;
	if(beg<end)
	{
		loc = partition(a,beg,end);
		printf("\nPass %d : ",i++);
		display_array(a,size);
		quick_sort(a,beg,loc-1);
		quick_sort(a,loc+1,end);
	}
}

        int partition(int a[], int beg, int end) 
    { 
        int left, right, temp, loc, flag; 
        loc = left = beg; 
        right = end; 
        flag = 0; 
        while(flag != 1) 
        { 
            while((a[loc] <= a[right]) && (loc!=right)) right--; 
            if(loc==right) 
            flag =1; 
            else if(a[loc]>a[right])
            { 
                temp = a[loc]; 
                a[loc] = a[right]; 
                a[right] = temp; 
                loc = right; 
            } 
                if(flag!=1) 
                { 
                    while((a[loc] >= a[left]) && (loc!=left)) left++; 
                    if(loc==left) 
                    flag =1; 
                    else if(a[loc] <a[left]) 
                    { 
                        temp = a[loc]; 
                        a[loc] = a[left]; 
                        a[left] = temp; 
                        loc = left; 
                } 
        } 
            } // end while 
return loc; 
}
void display_array(int arr[],int n)
{
	int i;
	printf("\nThe array is :  ");
	for(i=0;i<n;i++)
	{
		printf("%d\t",arr[i]);
	}	
}