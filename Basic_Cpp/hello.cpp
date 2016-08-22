#include <iostream>
int main()
{
	std::cout << "Hello World\n"; // comments
	std::cout << "Hello!" << "\n";
	std::string a="Hi";
	char b[] = "Hi";
	std::cout << a.length() << " " << sizeof(b) << "\n";
	return 0;
}