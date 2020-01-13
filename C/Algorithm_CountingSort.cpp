/*
CountingSort 계수정렬

Non comparison sort algorithm
High Time Complexity 
Low Space Complexity
*/

#include <stdio.h>
#define MAXSIZE 8

void CountingSort(int* arr)
{
	//finding MIN, MAX;
	int MIN = arr[0];
	int MAX = arr[0];
	for(int i=1; i<MAXSIZE; i++)
	{
		if(MIN>arr[i])
		{
			MIN = arr[i];
		}
		if(MAX<arr[i])
		{
			MAX = arr[i];
		}
	}
	
	//Making Counting array
	int C_SIZE = MAX-MIN+1;
	int C_arr[C_SIZE] = {0};
	for(int i=0; i<MAXSIZE; i++)
	{
		C_arr[arr[i]-MIN]++;
	}
	for(int i=1; i<C_SIZE; i++)	//Accumulate C_arr
	{
		C_arr[i] = C_arr[i-1]+C_arr[i];
	}
	
	//Sorting
	int new_arr[MAXSIZE];
	for(int i=0; i<MAXSIZE; i++)
	{
		C_arr[arr[i]-MIN]--;
		new_arr[C_arr[arr[i]-MIN]] = arr[i];
	}
	for(int i=0; i<MAXSIZE; i++)
	{
		arr[i] = new_arr[i];
	}
}

int main()
{
	int arr[MAXSIZE] = {2, 5, 3, 0, 2, 3, 0, 3};
	
	CountingSort(arr);
	
	for(int i=0; i<MAXSIZE; i++)
	{
		printf("%d ", arr[i]);
	}
}
