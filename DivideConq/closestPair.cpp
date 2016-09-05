#include <iostream>
#include <float.h>
#include <stdlib.h>
#include <math.h>
using namespace std;
 
struct Point
{
    int x, y;
};

float dist(Point a, Point b)
{
	return sqrt((a.x - b.x)*(a.x - b.x) + (a.y - b.y)*(a.y - b.y));
}

// O(n square) solution
float closestBruteForce(Point P[], int n)
{
	float m = dist(P[0],P[1]);
	for(int i = 0; i < n; i++)
	{
		for (int j = i+1; j < n; ++j)
		{
			if(dist(P[i],P[j]) < m)
				m = dist(P[i],P[j]);
		}
	}
	return m;
}

int compareX(const void* a, const void* b)
{
    Point *p1 = (Point *)a,  *p2 = (Point *)b;
    return (p1->x - p2->x);
}

int compareY(const void* a, const void* b)
{
    Point *p1 = (Point *)a,   *p2 = (Point *)b;
    return (p1->y - p2->y);
}

float stripClosest(Point strip[], int size, float d)
{
    float min = d;
    // This is a proven fact that this loop runs at most 6 times (geometry is of this form -> :::)
    for (int i = 0; i < size; ++i)
        for (int j = i+1; j < size && (strip[j].y - strip[i].y) < min; ++j)
            if (dist(strip[i],strip[j]) < min)
                min = dist(strip[i], strip[j]);
    return min;
}

float closestUtil(Point Px[], Point Py[], int n)
{
	if(n<=3)
		return closestBruteForce(Px,n);
	int m = n/2;

	Point Pyl[m+1];   // y sorted points on left of vertical line
    Point Pyr[n-m-1];  // y sorted points on right of vertical line
    int li = 0, ri = 0;  // indexes of left and right subarrays
    for (int i = 0; i < n; i++)
    {
      if (Py[i].x <= Px[m].x)
         Pyl[li++] = Py[i];
      else
         Pyr[ri++] = Py[i];
    }

    float dl = closestUtil(Px, Pyl, m);
    float dr = closestUtil(Px + m, Pyr, n-m);
    float d = min(dl, dr);

    Point strip[n];
    int j = 0;
    for (int i = 0; i < n; i++)
        if (abs(Py[i].x - Px[m].x) < d)
            strip[j++] = Py[i];
    return min(d, stripClosest(strip, j, d));
}

// O(n log n) solution
float closest(Point P[], int n)
{
    Point Px[n];
    Point Py[n];
    for (int i = 0; i < n; i++)
    {
        Px[i] = P[i];
        Py[i] = P[i];
    }
    qsort(Px, n, sizeof(Point), compareX);
    qsort(Py, n, sizeof(Point), compareY);
    return closestUtil(Px, Py, n);
}

int main()
{
    Point P[] = {{2, 3}, {12, 30}, {40, 50}, {5, 1}, {12, 10}, {3, 4}};
    int n = sizeof(P) / sizeof(P[0]);
    cout << "The smallest distance is " << closestBruteForce(P, n) << endl;
    cout << "The smallest distance is " << closest(P, n) << endl;
    return 0;
}