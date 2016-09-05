#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <iomanip>
using namespace std;

int main()
{
    float n;
    cin >> n;
    while(n!=0.00)
    {
        float t = 0.0;
        int c=0,counter=2;
        while(t < n)
        {
            c++;
            t = t + (1.0/counter);
            counter++;
        }
        cout << c << " card(s)" << endl;
        cin >> n;
    }
}