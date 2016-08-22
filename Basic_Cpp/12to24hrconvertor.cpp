#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

int main(){
    string time;
    cin >> time;
    if(time[8]=='A')
    {
        int a=(int)time[0]-48;
        a=a*10 + (int)time[1] - 48;
        if(a==12)
            a=a-12;
        if(a<10)
            cout << 0;
        cout << a << time.substr(2,6) << endl;
    }
    else
    {
        int a=(int)time[0]-48;
        a=a*10 + (int)time[1] - 48;
        if(a==12)
      		cout << a << time.substr(2,6) << endl;
      	else
      	{
      		a+=12;
	        if(a>=24)
	            a=a-24;
	        if(a<10)
	        	cout << 0;
	        cout << a << time.substr(2,6) << endl;
	    }
    }
    return 0;
}