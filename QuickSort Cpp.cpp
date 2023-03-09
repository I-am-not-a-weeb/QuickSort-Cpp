#include <iostream>

void swap(int* a, int* b)
{
	int tmp = *a;
	*a = *b;
	*b = tmp;
}

int partition(int* arr, int p, int r)
{
	int x = arr[r];
	int i = p - 1;
	for (int j = p; j <= r; j++)
	{
		if (arr[j] <= x)
		{
			i++;
			swap(&arr[i], &arr[j]);
		}
	}
	if (i < r) return i;
	else return i - 1;
}

void quickSort(int*arr,int p, int r)
{
	if (p < r)
	{
		int q = partition(arr, p, r);
		quickSort(arr, p, q);
		quickSort(arr, q + 1, r);
	}
}

void quickSortModified(int* arr, int p, int r)
{
	if (p < r)
	{
		int q = partition(arr, p, r);
		quickSortModified(arr, p, q);
		quickSortModified(arr, q + 1, r);
	}
}

int main()
{
	int tab[] = { 1,12,523,23,2,5,66,352,67512,4346,3434,6,3,3456,34,13 };

	int* arr = new int(sizeof(tab));

	int size = sizeof(tab)/sizeof(int);
	for (int i = 0; i < size; i++)
	{
		arr[i] = tab[i];
		std::cout << arr[i] << std::endl;
	}
	quickSort(arr, 0, size-1);
	std::cout << "sort:" << std::endl;
	for (int i = 0; i < size; i++)
	{
		std::cout << arr[i] << std::endl;
	}
}
