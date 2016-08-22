#include <iostream>
#include <cstdlib>
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
int choosePivot(int l,int r)
{
	return l+rand()%(r-l+1);
}
int partition(int arr[], int l, int r)
{
	int i,j=l-1;
	int p=choosePivot(l,r);
	std::swap(arr[p],arr[r]);
	p=arr[r];
	for(i=l;i<r;i++)
	{
		if(arr[i]<=p)
		{
			j++;
			std::swap(arr[j],arr[i]);
		}
	}
	std::swap(arr[j+1],arr[r]);
	return (j+1);
}
void quickSort(int arr[], int l, int r)
{
	if(l<r)
	{
	    int p=partition(arr,l,r);
		quickSort(arr,l,p-1);
		quickSort(arr,p+1,r);
	}
}
int main()
{
	srand(time(NULL));
	std::cout << "Enter size of array : ";
	int size=0;
	std::cin >> size;
	int arr[size];
	createArr(arr, size);
	std::cout << "Initially, ";
	printArr(arr, size);
	quickSort(arr,0,size-1);
	std::cout << "After sorting in ascending order, ";
	printArr(arr,size);
}