/*Write a program to calculate GCD of two numbers
(i) with recursion (ii) without recursion.
*/

// i) with recursion

#include <iostream>
using namespace std;

// Recursive function to calculate GCD
int gcdRecursive(int a, int b) {
    if (b == 0) {
        return a;
    }
    return gcdRecursive(b, a % b);
}

int main() {
    int num1, num2;

    cout << "Enter first number: ";
    cin >> num1;
    cout << "Enter second number: ";
    cin >> num2;

    int gcd = gcdRecursive(num1, num2);
    cout << "GCD of " << num1 << " and " << num2 << " is: " << gcd << endl;

    return 0;
}








// ii) without recursion
#include <iostream>
using namespace std;

// Function to calculate GCD without recursion
int gcd(int a, int b) {
    while (b != 0) {
        int temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

int main() {
    int num1, num2;

    cout << "Enter first number: ";
    cin >> num1;
    cout << "Enter second number: ";
    cin >> num2;

    int gcdValue = gcd(num1, num2);
    cout << "GCD of " << num1 << " and " << num2 << " is: " << gcdValue << endl;

    return 0;
}
