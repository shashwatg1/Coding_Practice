#include <iostream>
using namespace std;

int main()
{
	char a[100];
    cin >> a;
    int i=0;
    while(a[i])
    {
    	if(a[i]>='a'&&a[i]<='z')
	    	cout << char(a[i]-32);
	    else
	    	cout << char(a[i]+32);
    	i++;
    }
}
