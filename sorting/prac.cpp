#include <iostream>
#include <cstdlib>
int main()
{
	srand(time(NULL));
	int l=10,r=40;
	for (int i = 0; i < 10; ++i)
	{
		std::cout << l+rand()%(r-l+1) << " ";
	}
}