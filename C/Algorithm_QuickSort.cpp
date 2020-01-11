#include <stdio.h>
#define MAXSIZE 8

void QuickSort(int* arr, int first, int last)
{
	if(first<last)
	{
		int pivot = arr[last];
		int Bigger = first;	//divide from this index
		
		for(int i=first; i<last; i++)
		{
			if(arr[i] < pivot)
			{
				int tmp = arr[i];
				arr[i] = arr[Bigger];
				arr[Bigger] = tmp;
				
				Bigger++;
		}
		}
		arr[last] = arr[Bigger];
		arr[Bigger] = pivot;
		Bigger++;
		
		QuickSort(arr, first, Bigger-2);
		QuickSort(arr, Bigger, last);
	}

}



int main()
{
	int arr[MAXSIZE] = {2, 8, 7, 1, 3, 5, 6, 4};

	QuickSort(arr, 0, MAXSIZE-1);	

	for(int i=0; i<MAXSIZE; i++)
	{
		printf("%d ", arr[i]);
	}
}
