#include <iostream>

int merge(int arr[], int temp[], int left, int mid, int right)
{
	int i=left,j=mid,k=left,inv_count=0;
	while ((i <= mid - 1) && (j <= right))
	{
		if (arr[i] <= arr[j])
			temp[k++] = arr[i++];
		else
		{
			temp[k++] = arr[j++];
			inv_count = inv_count + (mid - i);
		}
	}
	while (i <= mid - 1)
		temp[k++] = arr[i++];
	while (j <= right)
		temp[k++] = arr[j++];
	for (i=left; i <= right; i++)
		arr[i] = temp[i];
	return inv_count;
}

int countInv(int a[], int temp[], int m, int n)
{
	int c=0;
	if(n>m)
	{
		int mid = (m+n)/2;
		c = countInv(a,temp,m,mid);
		c += countInv(a,temp,mid+1,n);
		c += merge(a,temp,m,mid+1,n);
	}
	return c;
}

void printArr(int arr[], int size)
{
	std::cout << "the array is : ";
	for (int i = 0; i < size; ++i)
		std::cout << arr[i] << " ";
	std::cout << "\n";
}

int main()
{
	int arr[] = {1, 20, 6, 4, 5};
  	int temp[5]={0};
  	printArr(arr,5);
  	printArr(temp,5);
  	std::cout << countInv(arr,temp,0,4) << std::endl;
  	printArr(arr,5);
  	printArr(temp,5);
}