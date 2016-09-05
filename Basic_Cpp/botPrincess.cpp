#include <iostream>
#include <vector>
#include <string>
using namespace std;
void displayPathtoPrincess(int n, vector <string> grid){
    int px=0,py=0,mx=0,my=0;
    for(int i=0; i<n; i++) {
        if(grid[i].find('m') < n)
            {
            mx=i;
            my=grid[i].find('m');
        }
        if(grid[i].find('p') < n)
            {
            px=i;
            py=grid[i].find('p');
        }
    }
    while(mx>px)
        {
        cout << "LEFT\n";
            mx--;
    }
    while(mx<px)
        {
        cout << "RIGHT\n";
            mx++;
    }
    while(my<py)
        {
        cout << "DOWN\n";
            my++;
    }
    while(my>py)
        {
        cout << "UP\n";
            my--;
    }
}
int main(void) {

    int m;
    vector <string> grid;

    cin >> m;

    for(int i=0; i<m; i++) {
        string s; cin >> s;
        grid.push_back(s);
    }

    displayPathtoPrincess(m,grid);

    return 0;
}
