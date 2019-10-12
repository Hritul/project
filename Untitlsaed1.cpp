#include<stdio.h>
#include<conio.h>
void swap(int *x,int *y)
{
	int temp=*x;
	*x=*y;
	*y=temp;
}

void bubbleSort(int a[],int n) 
{ 
   int i,j; 
   for (i = 0; i < n-1; i++)       
   for (j = 0; j < n-i-1; j++)  
	if (a[j] < a[j+1]) 
    swap(&a[j], &a[j+1]); 
} 
void printarray(int a[], int size) 
{ 
    int i; 
    for (i=0; i < size; i++) 
        printf("%d ", a[i]); 
    	printf("\n"); 
} 
void classreq(int a[],int n)
{
	int sum=0,count=0;
	while (sum < n)
	{
		sum += a[count];
		count++;
	}
	printf("%d", count);
}
int main()
{
	
	int arr[8][15], row, col, i, j, classrooms, sy, ty, remainingSY,remainingTY,size,f;
	printf("enter the number of SY students:\n");  
	scanf("%d",&sy);
	printf("enter the number of TY students:\n");	
	scanf("%d",&ty);
    f= sy+ty;
	printf("enter the number of classrooms:\n");
	int k;
	scanf("%d", &k);
	printf("enter the number of benches in each class:\n");
	int a[k];
	for (int i = 0 ; i < k; ++i) 
 	{
	 scanf("%d", &a[i]);
	}
    int n = sizeof(a)/sizeof(a[0]); 
    bubbleSort(a,n); 
    printf("Sorted classrooms in descending order is: \n"); 
    printarray(a,n); 
    printf("No. of classrooms required:/n");
    classreq(a,f);
}
