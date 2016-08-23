#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <iomanip>
using namespace std;

double calcMed(int a[], int l, int r)
{
	double med=0;
	int N=(r-l+1);
    if(N%2==1)
        med=a[l+ N/2];
    else
        med=(a[l + N/2]+a[l + N/2 - 1])/2.0;
    return med;
}
int main()
{
    int N;
    cin >> N;
    int c=0,a[N],f[N];
    for(int i=0;i<N;i++)
    	cin >> a[i];
    for(int i=0;i<N;i++)
    {
    	cin >> f[i];
    	c+=f[i];
    }
    int arr[c];
    c=0;
    for(int i=0;i<N;i++)
    {
    	for(int j=1;j<=f[i];j++)
    		arr[c++]=a[i];
    }
    sort(arr,arr+c);
    for (int i = 0; i < c; ++i)
        cout << arr[i] << " ";
    cout << endl;
    double q1,q3;
    q1=calcMed(arr,0,c/2 -1);
    q3=calcMed(arr,(c+1)/2,c-1);
    cout << c << endl << q1 << endl << q3 << endl << fixed << setprecision(1) << (q3-q1) << endl;
    return 0;   
}

n=55
0
26
l = 28
r = 54