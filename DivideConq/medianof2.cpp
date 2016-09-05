// There are 2 sorted arrays A and B of size n each.
// Write an algorithm to find the median of the array obtained after merging the above 2 arrays
#include <iostream>
using namespace std;

int getMedianLinearTime(int ar1[], int ar2[], int n)
{
    int i = 0, j = 0, count, m1 = -1, m2 = -1;
    for (count = 0; count <= n; count++)
    {
        if (i == n)
        {
            m1 = m2;
            m2 = ar2[0];
            break;
        }
        else if (j == n)
        {
            m1 = m2;
            m2 = ar1[0];
            break;
        } 
        if (ar1[i] < ar2[j])
        {
            m1 = m2;  /* Store the prev median */
            m2 = ar1[i];
            i++;
        }
        else
        {
            m1 = m2;  /* Store the prev median */
            m2 = ar2[j];
            j++;
        }
    }
    return (m1 + m2)/2;
}

// Above method is lenier time
// Below method is logarithmic time

int median(int arr[], int n)
{
    if (n%2 == 0)
        return (arr[n/2] + arr[n/2-1])/2;
    else
        return arr[n/2];
}
int getMedian(int ar1[], int ar2[], int n)
{
    if (n <= 0)
        return -1;
    if (n == 1)
        return (ar1[0] + ar2[0])/2;
    if (n == 2)
        return (max(ar1[0], ar2[0]) + min(ar1[1], ar2[1])) / 2;
 
    int m1 = median(ar1, n);
    int m2 = median(ar2, n);

    if (m1 == m2)
        return m1;
 
    // if m1 < m2 then median must exist in ar1[m1....] and ar2[....m2] 
    if (m1 < m2)
    {
        if (n % 2 == 0)
            return getMedian(ar1 + n/2 - 1, ar2, n - n/2 +1);
        return getMedian(ar1 + n/2, ar2, n - n/2);
    }
 
    // if m1 > m2 then median must exist in ar1[....m1] and ar2[m2...]
    if (n % 2 == 0)
        return getMedian(ar2 + n/2 - 1, ar1, n - n/2 + 1);
    return getMedian(ar2 + n/2, ar1, n - n/2);
}

int main()
{
	//only for arrays with equal size
	int A[] = {1, 12, 15, 26, 38};
    int B[] = {2, 13, 17, 30, 45};
	int size = sizeof(A)/sizeof(A[0]);
	cout << getMedian(A,B,size) << endl;
}