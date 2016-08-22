#include <iostream>
void printArr(int arr[], int size)
{
	std::cout << "the array is : ";
	for (int i = 0; i < size; ++i)
		std::cout << arr[i] << " ";
	std::cout << "\n";
}
void createArr(int arr[], int size)
{
	for(int i=0;i<size;i++)
	{
		std::cout << "Element " << i+1 << " -> Enter integer : ";
		std::cin >> arr[i];
	}
}
void bubbleSort(int arr[], int size)
{
	for (int i = 0; i < size-1; ++i)
	{
		int index = i;
		for (int j = 0; j < size-1-i; ++j)
		{
			if(arr[j]>arr[j+1])
				std::swap(arr[j],arr[j+1]);
		}
	}
}
int main()
{
	std::cout << "Enter size of array : ";
	int size=0;
	std::cin >> size;
	int arr[size];
	createArr(arr, size);
	std::cout << "Initially, ";
	printArr(arr, size);
	bubbleSort(arr,size);
	std::cout << "After sorting in ascending order, ";
	printArr(arr,size);
}