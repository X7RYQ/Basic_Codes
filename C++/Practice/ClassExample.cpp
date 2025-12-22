#include <iostream>
using namespace std;
class Example {
    private: 
    int x // Private field
    public: 
    Example(int a) { // Constructor
        x = a;
    }
    ~Example() { } // Destructor
    void setX (int a) // Method declared, defined outside class 
    int getX() { // Method defined inside class
        return x;
    }
};
void Example::setX (int a) { // Method defined outside class
    x = a;
}
int main () {
    Example obj1(5); // Constructor called
    cout << obj1.getX(); // Output: 5
    obj1.setX(10); // Method outside class called
    cout << obj1.getX(); // Output: 10
    return 0; // Destructor called automatically
}
