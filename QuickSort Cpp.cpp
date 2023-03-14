#include <iostream>
#include <chrono>
#include <random>

void swap(int* a, int* b)
{
	int tmp = *a;
	*a = *b;
	*b = tmp;
}

const int c = 100;

void insertionSort(int* arr,int n)
{
	
	for (int j = 1; j < n; j++)
	{
		int pom = arr[j];
		int i = j - 1;
		while (i >= 0 && arr[i] > pom)
		{
			arr[i + 1] = arr[i--];
		}
		arr[i + 1] = pom;
	}
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
	if (r - p + 1 < c)
	{
		insertionSort(arr, r);
		return;
	}
	if (p < r)
	{
		int q = partition(arr, p, r);
		quickSortModified(arr, p, q);
		quickSortModified(arr, q + 1, r);
	}
}

int* createArr(int n)
{
	int*arr = new int[n];
	for (int i = 0; i < n; i++)
	{
		arr[i] = i;
	}
	return arr;
}
int* createDescArr(int n)
{
	int* arr = new int[n];
	int j = n;
	for (int i = 0; i < n; i++,j--)
	{
		arr[i] = j;
	}
	return arr;
}

int* createRandArr(int n,int r)
{
	int* arr = new int[n];
	for (int i = 0; i < n; i++)
	{
		arr[i] = rand() % r;
	}
	return arr;
}

void Onotation(int* arr, int n)
{
	int* arr2 = new int(n);
	for (int i = 0; i < n; i++)
	{
		arr2[i] = arr[i];
	}
	auto start1 = std::chrono::high_resolution_clock::now();
	quickSort(arr, 0, n);
	auto stop1 = std::chrono::high_resolution_clock::now();

	auto start2 = std::chrono::high_resolution_clock::now();
	quickSortModified(arr2, 0, n);
	auto stop2 = std::chrono::high_resolution_clock::now();

	auto zed1 = std::chrono::duration_cast<std::chrono::microseconds>(stop1 - start1).count();
	auto zed2 = std::chrono::duration_cast<std::chrono::microseconds>(stop2 - start2).count();

	std::cout << "N = " << n;
	std::cout << " QuickSort: " << zed1;
	std::cout << "us QuickSortModified: " << zed2  << "us" << std::endl;
}

int main()
{
	srand(time(NULL));

	int tab[] = { 1,12,523,23,2,5,66,352,67512,4346,3434,6,3,3456,34,13 };

	int* arr = new int(sizeof(tab));

	int size = sizeof(tab)/sizeof(int);
	for (int i = 0; i < size; i++)
	{
		arr[i] = tab[i];
		std::cout << arr[i] << std::endl;
	}
	std::cout << "sort" << std::endl;
	quickSortModified(arr, 0, size);
	for (int i = 0; i < size; i++)
	{
		std::cout << arr[i] << std::endl;
	}
	int* arr1 = createArr(10);
	int* arr2 = createArr(100);
	int* arr3 = createArr(1000);
	//int* arr4 = createArr(10000);
	int* darr1 = createDescArr(10);
	int* darr2 = createDescArr(100);
	int* darr3 = createDescArr(1000);
	//int* darr4 = createDescArr(10000);
	int* rarr1 = createRandArr(10,10);
	int* rarr2 = createRandArr(100,100);
	int* rarr3 = createRandArr(1000, 1000);
	//int* rarr4 = createRandArr(10000, 10000);

	std::cout << "Asc: "; Onotation(arr1, 10);
	std::cout << "Desc: "; Onotation(darr1, 10);
	std::cout << "Rand: "; Onotation(rarr1, 10);

	std::cout << "Asc: "; Onotation(arr2, 100);
	std::cout << "Desc: "; Onotation(darr2, 100);
	std::cout << "Rand: "; Onotation(rarr2, 100);

	std::cout << "Asc: "; Onotation(arr3, 1000);
	std::cout << "Desc: "; Onotation(darr3, 1000);
	std::cout << "Rand: "; Onotation(rarr3, 1000);

	//std::cout << "Asc: "; Onotation(arr4, 10000); 
	//std::cout << "Desc: "; Onotation(darr4, 10000);
	//std::cout << "Rand: "; Onotation(rarr4, 10000);
}

