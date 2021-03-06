// digit by digit sort starting from least significant digit to most significant digit
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
void countingsort(int arr[], int n, int exp)
{
    int output[n];
    int i, count[BUCKET_K] = {0};
    for (i = 0; i < n; i++)
        count[(arr[i]/exp)%10]++;
    for (i = 1; i < 10; i++)
        count[i] += count[i - 1]; 
    for (i = n - 1; i >= 0; i--)
    {
        output[count[(arr[i]/exp)%10] - 1] = arr[i];
        count[(arr[i]/exp)%10]--;
    }
    for (i = 0; i < n; i++)
        arr[i] = output[i];
}
void radixSort(int arr[], int n)
{
	int mx = arr[0];
    for (int i = 1; i < n; i++)
        if (arr[i] > mx)
            mx = arr[i];
    for (int exp = 1; mx/exp > 0; exp *= 10)
        countingsort(arr, n, exp);
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
	radixSort(arr, size);
	std::cout << "After sorting in ascending order, ";
	printArr(arr,size);
}