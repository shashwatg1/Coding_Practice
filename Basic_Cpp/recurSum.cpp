#include <iostream>
using namespace std;
long long num(long long c)
{
	while((c/10)!=0)
	{
		long long k=0;
		while((c/10) > 0)
		{
			k+=(c%10);
			c/=10;
		}
		k+=c;
		c=k;
	}
	return c;
}

int main()
{
	long long t;
	cin >> t;
	while(t--)
	{
		long long m,c=0;
		cin >> m;
		while(m--)
		{
			long long l,d;
			cin >> l >> d;
			c+=num(l*d);
		}
		c = num(c);
		cout << c << "\n";
	}
}