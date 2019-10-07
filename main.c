#include<stdio.h>
int a[20];

void arrayGraph()
{
    int i,j;
    system("cls");
    for(i=0;i<20;i++)
    {
        printf("\n");
        for(j=0;j<a[i];j++)
        {
             printf("*");
        }
    }
}

int partition(int low,int high)
{
	int i,j,x,temp;
	i=low;
	x=a[low];
	j=high;
	while(i<=j)
	{
		while(a[i]<=x && i<=high)
		{
			i++;
		}
		while(a[j] > x)
		{
			j--;
		}
		if(i<j)
		{
			temp=a[i];
			a[i]=a[j];
			a[j]=temp;
			arrayGraph();
		}
	}
	a[low]=a[j];
	a[j]=x;
	arrayGraph();
	return(j);
}

void quiksort(int low,int high)
{
	int j;
	if(low<high)
	{
		j=partition(low,high);
		quiksort(low,j-1);
		quiksort(j+1,high);
	}
}

void bubbleSort()
{
   int temp,i,j;
   for(i = 19; i >= 0; i--)
   {
      for(j = 1; j <= i; j++)
      {
         if (a[j-1] > a[j])
         {
              temp = a[j-1];
              a[j-1] = a[j];
              a[j] = temp;
              arrayGraph();
         }
      }
   }
}

void merge(int l, int m, int r)
{
    int i, j, k;
    int n1 = m - l + 1;
    int n2 =  r - m;

    /* create temp arrays */
    int L[n1], R[n2];

    /* Copy data to temp arrays L[] and R[] */
    for (i = 0; i < n1; i++)
        L[i] = a[l + i];
    for (j = 0; j < n2; j++)
        R[j] = a[m + 1+ j];

    /* Merge the temp arrays back into arr[l..r]*/
    i = 0; // Initial index of first subarray
    j = 0; // Initial index of second subarray
    k = l; // Initial index of merged subarray
    while (i < n1 && j < n2)
    {
        if (L[i] <= R[j])
        {
            a[k] = L[i];
            i++;
        }
        else
        {
            a[k] = R[j];
            j++;
        }
        k++;
    }

    /* Copy the remaining elements of L[], if there
       are any */
    while (i < n1)
    {
        a[k] = L[i];
        i++;
        k++;
    }

    /* Copy the remaining elements of R[], if there
       are any */
    while (j < n2)
    {
        a[k] = R[j];
        j++;
        k++;
    }
}

/* l is for left index and r is right index of the
   sub-array of arr to be sorted */
void mergeSort(int l, int r)
{
    if (l < r)
    {
        // Same as (l+r)/2, but avoids overflow for
        // large l and h
        int m = l+(r-l)/2;

        // Sort first and second halves
        mergeSort(l, m);
        mergeSort(m+1, r);
        arrayGraph();
        merge(l, m, r);
    }
}

void insertionSort()
{
    int i,key, j;
    for (i = 1; i < 20; i++)
    {
        key = a[i];
        j = i - 1;

        /* Move elements of arr[0..i-1], that are
        greater than key, to one position ahead
        of their current position */
        while (j >= 0 && a[j] > key)
        {
            a[j + 1] = a[j];
            j = j - 1;
            arrayGraph();
        }
        a[j + 1] = key;
    }
}

void main()
{
	int i,j;
	printf("Enter 20 elements");
	for(i=0;i<20;i++)
	{
		scanf("%d",&a[i]);
	}
	arrayGraph();
	printf("\n1:bubble sort \n2:quick sort\n3:merge sort\n4:insertion sort");
	scanf("%d",&j);
	if(j==1)
        bubbleSort();
    else if(j==2)
        quiksort(0,19);
    else if(j==3)
        mergeSort(0,19);
    else
        insertionSort();
	arrayGraph();
	getch();
}
