#include <stdio.h>
#define MAXSIZE 6

void SelectionSort(int arr[MAXSIZE])
{ 
	for(int i=0; i<MAXSIZE-1; i++)
	{
		//selecting minimum
		int min = arr[i];
		int min_index = i;
		for(int j=i; j<MAXSIZE-1; j++)
		{
			if(min>arr[j+1])	//ascending
			{
				min = arr[j+1];
				min_index = j+1;
			}
		}
		//swap
		arr[min_index] = arr[i];
		arr[i] = min;
	}
}

int main()
{
	int arr[MAXSIZE] = {5, 2, 4, 6, 1, 3};
	
	SelectionSort(arr);
	
	for(int i=0; i<MAXSIZE; i++)
	{
		printf("%d ", arr[i]);
	}
}
