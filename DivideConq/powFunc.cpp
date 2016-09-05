#include <iostream>
using namespace std;
float powerfunc(float x,int n)
{
	if(n==0)
		return 1;
	float temp = powerfunc(x,n/2);
	if(n%2==0)
		return temp*temp;
	else if(n>0)
		return x*temp*temp;
	else
		return (temp*temp)/x;
}
int main()
{
	float x;
	int n;
	cin >> x >> n;
	cout << x << " ^ " << n << " = " << powerfunc(x,n) << endl;
}