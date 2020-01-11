#include <stdio.h>
#define MAXSIZE 6

void MergeSort(int* arr, int first, int last)
{
	if (first < last)	//if there's more than one element, divide array
	{
		int middle = (first+last)/2;
		MergeSort(arr, first, middle);
		MergeSort(arr, middle+1, last);
		
		//Merge
		int first_1 = first;
		int last_1 = middle;
		int first_2 = middle+1;
		int last_2 = last;
		int new_arr[last-first+1];
		int count = 0;
		while(first_1<=last_1 && first_2<=last_2)
		{
			if(arr[first_1]<arr[first_2])
			{
				new_arr[count] = arr[first_1];
				first_1++;
			}
			else
			{
				new_arr[count] = arr[first_2];
				first_2++;
			}
			count++;
		}
		while(count<=last)
		{
			if(first_1>last_1)
			{
				for(int i=first_2; i<=last_2; i++)
				{
					new_arr[count] = arr[i];
					count++;
				}
			}
			else
			{
				for(int i=first_1; i<=last_1; i++)
				{
					new_arr[count] = arr[i];
					count++;
				}
			}
		}
		
		count = 0;
		for(int i=first; i<=last; i++)
		{
			arr[i] = new_arr[count];
			count++;
		}
	}
}



int main()
{
	int arr[MAXSIZE] = {5, 2, 4, 6, 1, 3};
	
	MergeSort(arr, 0, MAXSIZE-1);	
	
	for(int i=0; i<MAXSIZE; i++)
	{
		printf("%d ", arr[i]);
	}
}
