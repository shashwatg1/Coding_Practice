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
double stanDev(int a[],int n,double mean)
{
    double c=0;
    for (int i = 0; i < n; ++i)
        c = c + (a[i]-mean)*(a[i]-mean);
    c=c/n;
    return sqrt(c);
}
int main()
{
    int N;
    cin >> N;
    int a[N];
    for(int i=0;i<N;i++)
    	cin >> a[i];
    sort(a,a+N);
    for(int i=0;i<N;i++)
    	cout << a[i] << " ";
    cout << endl;

    double mean=a[0];
    for(int i=1;i<N;i++)
        mean+=a[i];
    mean=mean/N;
    
    double sd = stanDev(a,N,mean);

    int counter = 1,max = 0,mode = a[0];
    for (int i = 0; i < N - 1; i++)
    {
        if ( a[i] == a[i+1] )
        {
            counter++;
            if ( counter > max )
            {
                max = counter;
                mode = a[i];
            }
        }
        else
            counter = 1; // reset counter.
    }    
    
    double q1,med,q3;
    med=calcMed(a,0,N-1);
    q1=calcMed(a,0,N/2 -1);
    q3=calcMed(a,(N+1)/2,N-1);
    cout << mean << endl << sd << endl << med << endl << mode << endl << q1 << endl << q3 << endl;
    return 0;
}
