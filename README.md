#include<stdio.h>
#include<conio.h>
#include<stdlib.h>

int *compute(int rows, int columns, int classRoom[][columns], int remainingSY, int remainingTY, int classRoomNo, int *remainingStudents) 
{
		//Assign 0 by default
		int i,j;
		for(i=0; i<rows; i++)
		 {
            for(j=0; j<columns; j++)
			 {
                classRoom[i][j] = 0;
            }
		}

		int firstSY = 1;
		if(remainingTY > remainingSY) 
		{
			firstSY  = 0;
		}
		/*
		 * firstSY is true when number of SY students > number of TY students
		 * So, we fill fill the 2-D array in the following manner
		 * 2 3 2 3 2 3
		 * 3 2 3 2 3 2
		 * 2 3 2 3 2 3
		 * 3 2 3 2 3 2
		 *
		 * Else if TY students > SY students, the array will be filled in
		 * 3 2 3 2 3 2
		 * 2 3 2 3 2 3
		 * 3 2 3 2 3 2
		 * 2 3 2 3 2 3
		 *
		 */
		for(i=0; i<rows; i++) 
		{
			for(j=0; j<columns; j++) 
			{
				//Case for indexes like [0,0], [0, 2], [2,0], [2,2], [1,1], [1,3], [3,1], [3,3],....
				if((i%2 == 0 && j%2 == 0) || (i%2 == 1 && j%2 == 1)) 
				{
					if(firstSY == 1) 
					{
						if(remainingSY > 0) 
						{
							classRoom[i][j] = 2;
							remainingSY--;
						} else 
						{
							classRoom[i][j] = 0;
						}
					} 
					else
					{
						if(remainingTY > 0) 
						{
							classRoom[i][j] = 3;
							remainingTY--;
						} else 
						{
							classRoom[i][j] = 0;
						}
					}
				}
				//Case for indexes like [0,1], [0, 3], [2,1], [2,3], [1,0], [1,2], [3,0], [3,2],....
				else 
				{
					if(firstSY == 1) 
					{
						if(remainingTY > 0) 
						{
							classRoom[i][j] = 3;
							remainingTY--;
						} else {
							classRoom[i][j] = 0;
						}
					} 
					else 
					{
						if(remainingSY > 0) 
						{
							classRoom[i][j] = 2;
							remainingSY--;
						} else
						{
							classRoom[i][j] = 0;
						}
					}
				}
			}
		}

        printf("Seating arrangement for classroom %d: \n", classRoomNo);
		for(i=0; i<rows; i++) 
		{
            for(j=0; j<columns; j++) 
			{
                printf("%d ", classRoom[i][j]);
            }
            printf("\n");
		}

		remainingStudents[0] = remainingSY;
		remainingStudents[1] = remainingTY;
		return remainingStudents;
	}

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

	int sy, ty;
	printf("enter the number of SY students:\n");
	scanf("%d",&sy);
	printf("enter the number of TY students:\n");
	scanf("%d",&ty);
	printf("enter the number of classrooms:\n");
	int k;
	scanf("%d", &k);
	printf("enter the number of benches in each class:\n");
	int a[k],i;
	for (i = 0 ; i < k; ++i)
 	{
	 scanf("%d", &a[i]);
	}
    int n = sizeof(a)/sizeof(a[0]);
    bubbleSort(a,n);
    printf("Sorted classrooms in descending order is: \n");
    printarray(a,n);

    int rows, columns, remainingSY, remainingTY;
    remainingSY = sy;
    remainingTY = ty;
    int currentStudents[2];
    int count = 0;
    for(count=0; count<k && (remainingSY>0 || remainingTY>0); count++) 
	{
        printf("Enter the number of rows for classroom %d with %d benches:\n", count+1, a[count]);
        scanf("%d", &rows);
        printf("Enter the number of columns for classroom %d with %d benches:\n", count+1, a[count]);
        scanf("%d", &columns);
        if(rows*columns != a[count]) 
		{
            printf("Please enter the correct number of rows and columns such that rows*columns = total benches\n");
            break;
        }
        int classRoom[rows][columns];
        int *remainingStudents = compute(rows, columns, classRoom, remainingSY, remainingTY, count+1, currentStudents);
        remainingSY = remainingStudents[0];
        remainingTY = remainingStudents[1];
        printf("Remaining SY students: %d\n", remainingSY);
        printf("Remaining TY students: %d\n", remainingTY);
    }

    printf("Total classrooms required: %d", count);
}
