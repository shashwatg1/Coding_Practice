#include <iostream>
 
double getDouble()
{
    std::cout << "Enter a double value: ";
    double x;
    std::cin >> x;
    return x;
}
 
char getOperator()
{
    std::cout << "Enter one of the following: +, -, *, or /: ";
    char op;
    std::cin >> op;
    return op;
}
 
void printResult(double x, char op, double y)
{
    if (op == '+')
        std::cout << x << " + " << y << " is " << x + y << '\n';
    else if (op == '-')
        std::cout << x << " - " << y << " is " << x - y << '\n';
    else if (op == '*')
        std::cout << x << " * " << y << " is " << x * y << '\n';
    else if (op == '/')
        std::cout << x << " / " << y << " is " << x / y << '\n';
}
 
int main()
{
    double x = getDouble();
    char op = getOperator();
    double y = getDouble();
 
    printResult(x, op, y);
 
    return 0;
}