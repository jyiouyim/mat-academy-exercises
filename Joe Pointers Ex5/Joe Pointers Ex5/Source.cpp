#include <iostream>

using namespace std;

int arr[] = { 23, 44, 22, 21, 16, 7, 91 };

namespace {

	int i = 0;

	void swap(int *xp, int *yp)
	{
		int temp = *xp;
		*xp = *yp;
		*yp = temp;
	}

	void bubbleSort(int* arr, int n)  //pointer variable 
	{
		for (int i = 0; i < n - 1; i++)
			for (int j = 0; j < n - i - 1; j++)
				if (*(arr+j) > *(arr+j + 1))
					swap(&*(arr + j), &*(arr + j + 1));
	}
}

void printArray(int* arr, int size = 0) //pointer variable 
{
	for (int i = 0; size>0; size--, i++)
		cout << *(arr+i) << " ";
	cout << endl;

	return;
}

int main()
{
	int arr[] = { 64, 34, 25, 12, 22, 11, 90 };
	int n = sizeof(arr) / sizeof(arr[0]);
	cout << "Sorted array: \n";
	bubbleSort(::arr,n);
	printArray(::arr, n);
	cout << "Sorted array: \n";
	bubbleSort(arr, n);
	printArray(arr, n);

	return 0;
}
