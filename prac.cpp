#include <iostream>
using namespace std;

int main()
{
    int N,Q;
    cin >> N >> Q;
    int a[3000][3000];
    cout << "yo1";
    for(int i=0;i<N;i++)
    {
        int k;
        cin >> k;
        for(int j=0;j<k;j++)
            cin >> a[i][j];
    }
    cout << "yo";
    for(int i=0;i<Q;i++)
    {
        int x,y;
        cin >> x >> y;
        cout << a[x][y] << endl;
    }
    return 0;
}
