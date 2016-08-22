// how many different squares are there in a grid of N ×N squares. for N=2, the answer is 5

#include <iostream>
int main()
{
	int n;
	std::cin >> n;
	while(n!=0)
	{
		std::cout << n*(n+1)*(2*n+1)/6 << "\n";
		std::cin >> n;
	}
}