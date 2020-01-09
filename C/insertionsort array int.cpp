#include <stdio.h>
#define MAXSIZE 6

void InsertionSort(int arr[MAXSIZE])
{
	for(int i=1; i<MAXSIZE; i++)	//key does not includet arr[0]
	{
		int key = arr[i];
		
		int shift_index = i-1;
		while(arr[shift_index]>key && shift_index>=0)
		{
			arr[shift_index+1] = arr[shift_index];
			shift_index--;
		}
		arr[shift_index+1] = key;
	}
}

int main()
{
	int arr[MAXSIZE] = {5, 2, 4, 6, 1, 3};
	
	InsertionSort(arr);
	
	for(int i=0; i<MAXSIZE; i++)
	{
		printf("%d ", arr[i]);
	}
}
