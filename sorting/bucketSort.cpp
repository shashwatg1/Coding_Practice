// decimal numbers in a range
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
void printArr(float arr[], int size)
{
	std::cout << "the array is : ";
	for (int i = 0; i < size; ++i)
		std::cout << arr[i] << " ";
	std::cout << "\n";
}
void createArr(float arr[], int size)
{
	for(int i=0;i<size;i++)
	{
		std::cout << "Element " << i+1 << " -> Enter Value : ";
		std::cin >> arr[i];
	}
}
void bucketSort(float arr[], int n)
{
    // 1) Create n empty buckets
    vector<float> b[n];	
    // 2) Put array elements in different buckets
    for (int i=0; i<n; i++)
    {
       int bi = n*arr[i]; // Index in bucket
       b[bi].push_back(arr[i]);
    }
    // 3) Sort individual buckets
    for (int i=0; i<n; i++)
       std::sort(b[i].begin(), b[i].end()); 
    // 4) Concatenate all buckets into arr[]
    int index = 0;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < b[i].size(); j++)
          arr[index++] = b[i][j];
}
int main()
{
	std::cout << "Enter size of array : ";
	int size=0;
	std::cin >> size;
	float arr[size];
	createArr(arr, size);
	std::cout << "Initially, ";
	printArr(arr, size);
	bucketSort(arr, size);
	std::cout << "After sorting in ascending order, ";
	printArr(arr,size);
}