/*
Given two numbers A and B. Find the value of pair (P,Q) such that A <= P < Q <= B value of P AND Q is maximum where AND is a binary operator

Input:
First line of input contains number of test cases T. Each test case contains two numbers A and B.

Output: For each test case print the value of maximum AND
*/
#include <iostream>
using namespace std;

int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		long long a,b,ans;
		cin >> a >>b;
		if(b%2==0)
		ans=b-2;
		else
		ans=b-1;
		if(ans>=a)
		cout<<ans<<endl;
		else
		{
			ans=a&b;
			cout<<ans<<endl;
		}
	}
}