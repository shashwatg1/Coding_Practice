#include <iostream>
 
int cout() // declares our own "cout" function
{
    return 5;
}
 
int main()
{
    using namespace std; // makes std::cout accessible as "cout"
    cout << "Hello, world!"; // uh oh!  Which cout do we want here?
 
    return 0;
}

/*
we get an error because of collision of couts's
*/