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
void merge(int arr[], int l, int m, int r)
{
    int i,j,k;
    int n1 = m - l + 1;
    int n2 =  r - m;
    int L[n1], R[n2];
    for (i = 0; i < n1; i++)
        L[i] = arr[l + i];
    for (j = 0; j < n2; j++)
        R[j] = arr[m + 1 + j];
    i=0;j=0;k=l;
    while(i<n1 && j<n2)
    {
    	if(L[i]<=R[j])
    		arr[k++]=L[i++];
    	else
    		arr[k++]=R[j++];
    }
    while(i<n1)
    	arr[k++]=L[i++];
    while(j<n2)
    	arr[k++]=R[j++];
}
void mergeSort(int arr[], int l, int r)
{
	if(l<r)
	{
	    int m = l+(r-l)/2;
		mergeSort(arr,l,m);
		mergeSort(arr,m+1,r);
		merge(arr,l,m,r);
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
	mergeSort(arr,0,size-1);
	std::cout << "After sorting in ascending order, ";
	printArr(arr,size);
}
