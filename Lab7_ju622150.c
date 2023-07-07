#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include<stdlib.h>



void swap(int* arr, int i, int j) {
	int temp = arr[i];
	arr[i] = arr[j];
	arr[j] = temp;
}


void bubbleSort(int arr[], int n, int swaps[])
{
	int i, j;
	int totalSwaps = 0;
	for (i = 0; i < n - 1; i++)
	{
		for (j = 0; j < n - i - 1; j++)
		{
			if (arr[j] > arr[j + 1])
			{
				swap(arr, j, j + 1);
				swaps[i]++;
				totalSwaps++;
				
			}
		}
	}
	printf("Total number of swaps: %d\n", totalSwaps);
}


void printArray(int arr[], int size)
{
	int i;
	for (i = 0; i < size; i++)
		printf("%d ", arr[i]);
	printf("\n");
}


int main()
{
	int arr[] = {97,16,45,63,13,22,7,58,72};
	int n = sizeof(arr) / sizeof(arr[0]);
	

	int* swaps = (int*)malloc(n * sizeof(int));
	if (swaps == NULL)
		return 1;
	for (int i = 0; i < n; i++)
	{
		swaps[i] = 0;
	}

	bubbleSort(arr, n,swaps);
	printf("Sorted array: ");
	printArray(arr, n);
	printf("Index\tSwaps\n");
	for (int i = 0; i < n; i++)
	{
		printf("%d\t%d\n", i, swaps[i]);
	}

	free(swaps);
	return 0;
}
