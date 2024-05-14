/*Create a Triangle class. Add exception handling statements to ensure the following
conditions: all sides are greater than 0 and sum of any two sides are greater than the
third side. The class should also have overloaded functions for calculating the area of
a right angled triangle as well as using Heron's formula to calculate the area of any type
of triangle*/

#include <iostream>
#include <cmath> // For sqrt() function
using namespace std;

class Triangle {
private:
    double side1, side2, side3;

public:
    Triangle(double s1, double s2, double s3) : side1(s1), side2(s2), side3(s3) {
        if (side1 <= 0 || side2 <= 0 || side3 <= 0) {
            throw invalid_argument("All sides of the triangle must be greater than 0.");
        }
        if (side1 + side2 <= side3 || side1 + side3 <= side2 || side2 + side3 <= side1) {
            throw invalid_argument("Sum of any two sides of the triangle must be greater than the third side.");
        }
    }

    // Function to calculate the area of a right-angled triangle
    double calculateArea() const {
        return 0.5 * side1 * side2;
    }

    // Function to calculate the area of any type of triangle using Heron's formula
    double calculateArea(double s1, double s2, double s3) const {
        double s = (s1 + s2 + s3) / 2;
        return sqrt(s * (s - s1) * (s - s2) * (s - s3));
    }
};

int main() {
    try {
        double side1, side2, side3;

        cout << "Enter the lengths of the sides of the triangle: ";
        cin >> side1 >> side2 >> side3;

        Triangle triangle(side1, side2, side3);

        double area;
        if (side1 * side1 + side2 * side2 == side3 * side3 || side1 * side1 + side3 * side3 == side2 * side2 ||
            side2 * side2 + side3 * side3 == side1 * side1) {
            area = triangle.calculateArea(); // Right-angled triangle
        } else {
            area = triangle.calculateArea(side1, side2, side3); // Any type of triangle
        }

        cout << "Area of the triangle: " << area << endl;
    } catch (const invalid_argument& e) {
        cout << "Exception caught: " << e.what() << endl;
    }

    return 0;
}
