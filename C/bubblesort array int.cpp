#include <stdio.h>
#define MAXSIZE 10

int Compare(int a, int b)
{
	return a>b;	//순서 틀리면 return 1 
}

void BubbleSort(int arr[])
{
	int tmp;
	
	for(int i=MAXSIZE-1; i>0; i--)
	{
		for(int j=0; j<i; j++)
		{
			if(Compare(arr[j], arr[j+1]))
			{
				tmp = arr[j];
				arr[j] = arr[j+1];
				arr[j+1] = tmp;
			}
		}
	}
}

void Show(int arr[])
{
	for(int i=0; i<MAXSIZE; i++)
	{
		printf("%d ", arr[i]);
	}
}

int main()
{
	int arr[MAXSIZE] = {6, 5, 2, 9, 4, 7, 1, 3, 10, 8};
	
	BubbleSort(arr);
	Show(arr);
}
