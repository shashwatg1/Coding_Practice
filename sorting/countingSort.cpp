//O(n+k) time...linear..But elements must be between 1 to BUCKET_K
#include <iostream>
using namespace std;
const int BUCKET_K = 10;
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
void countingsortSimplified(int input[], int n)
{
    int CountArr[BUCKET_K] = { 0 };
    for (int i=0;i<n;i++)
        CountArr[input[i]]++;
    int k=0;
    for (int j=0;j<BUCKET_K;j++)
    {
        while (CountArr[j]--)
            input[k++] = j;
    }
}
void countingsort(int arr[], int n)
{
    int output[n]; // output array
    int i, count[BUCKET_K] = {0};
    // Store count of occurrences in count[]
    for (i = 0; i < n; i++)
        count[arr[i]]++;
    // Change count[i] so that count[i] now contains actual
    //  position of this digit in output[]
    for (i = 1; i < 10; i++)
        count[i] += count[i - 1]; 
    // Build the output array
    for (i = n - 1; i >= 0; i--)
    {
        output[count[arr[i]] - 1] = arr[i];
        count[arr[i]]--;
    }
    // Copy the output array to arr[], so that arr[] now
    // contains sorted numbers according to current digit
    for (i = 0; i < n; i++)
        arr[i] = output[i];
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
	countingsort(arr, size);
	std::cout << "After sorting in ascending order, ";
	printArr(arr,size);
}