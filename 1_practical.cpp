/* Write a program to compute the sum of the first n terms of the following series:

The number of terms n is to be taken from the user through the command line. If the
command line argument is not found then prompt the user to enter the value of n.
*/
#include <iostream>
using namespace std;

float compute_series(int n) {
    float sum = 1.0;
    for (int i = 2; i <= n; i++) {
        float term = 1.0 / (i * i);
        if (i % 2 == 0) {
            sum -= term;
        } else {
            sum += term;
        }
    }
    return sum;
}

int main(int argc, char* argv[]) {
    int number;
    if (argc == 2) {
        // If a command line argument is provided, use it as n
        number = atoi(argv[1]);
    } else {
        // If no command line argument is provided, prompt the user
        cout << "Enter the value of n: ";
        cin >> number;
    }

    cout << "The sum of the first " << number << " terms is: " << compute_series(number) << endl;

    return 0;
}

