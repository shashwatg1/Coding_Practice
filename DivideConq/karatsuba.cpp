// Given two binary strings that represent value of two integers, find the product of two strings
#include <iostream>
#include <string>
using namespace std;

int makeEqualLength(string &str1, string &str2)
{
    int len1 = str1.size();
    int len2 = str2.size();
    if (len1 < len2)
    {
        for (int i = 0 ; i < len2 - len1 ; i++)
            str1 = '0' + str1;
        return len2;
    }
    else if (len1 > len2)
    {
        for (int i = 0 ; i < len1 - len2 ; i++)
            str2 = '0' + str2;
    }
    return len1; // If len1 >= len2
}

int multiplyiSingleBit(string a, string b)
{
	return (a[0] - '0')*(b[0] - '0');
}

string addBitStrings( string first, string second )
{
    string result = "";
    int length = makeEqualLength(first, second);
    int carry = 0;
    for (int i = length-1 ; i >= 0 ; i--)
    {
        int firstBit = first[i] - '0';
        int secondBit = second[i] - '0';
        int sum = (firstBit ^ secondBit ^ carry)+ '0';
        result = (char)sum + result;
        carry = (firstBit&secondBit) | (secondBit&carry) | (firstBit&carry);
    }
    if (carry)
    	result = '1' + result;
    return result;
}

long int multi(string a, string b)
{
	int l = makeEqualLength(a,b);
	if(l==0)
		return 0;
	if(l==1)
		return multiplyiSingleBit(a,b);

	string al = a.substr(0, l/2);
	string ar = a.substr(l/2, l);
	string bl = b.substr(0, l/2);
	string br = b.substr(l/2, l);

    long int P1 = multi(al, bl);
    long int P2 = multi(ar, br);
    long int P3 = multi(addBitStrings(al, ar), addBitStrings(bl, br));
    return P1*(1<<(2*(l - l/2))) + (P3 - P1 - P2)*(1<<(l - l/2)) + P2;
}

int main()
{
	string a,b;
	cin >> a >> b;
	cout << multi(a,b) << endl;
}