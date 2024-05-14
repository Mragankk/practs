/* Create a Matrix class. Write a menu-driven program to perform following Matrix
operations (exceptions should be thrown by the functions if matrices passed to them are
incompatible and handled by the main() function):
a. Sum
b. Product
c. Transpose*/

#include <iostream>
#include <vector>
using namespace std;

class Matrix {
private:
    int rows, cols;
    vector<vector<int>> mat;

public:
    // Constructor to initialize the matrix
    Matrix(int rows, int cols) : rows(rows), cols(cols), mat(rows, vector<int>(cols, 0)) {}

    // Function to set value at a particular position in the matrix
    void setValue(int i, int j, int value) {
        if (i < 0 || i >= rows || j < 0 || j >= cols) {
            throw invalid_argument("Invalid index!");
        }
        mat[i][j] = value;
    }

    // Function to get value at a particular position in the matrix
    int getValue(int i, int j) const {
        if (i < 0 || i >= rows || j < 0 || j >= cols) {
            throw invalid_argument("Invalid index!");
        }
        return mat[i][j];
    }

    // Function to add two matrices
    Matrix add(const Matrix& other) const {
        if (rows != other.rows || cols != other.cols) {
            throw invalid_argument("Matrices are not compatible for addition!");
        }
        Matrix result(rows, cols);
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                result.setValue(i, j, mat[i][j] + other.getValue(i, j));
            }
        }
        return result;
    }

    // Function to multiply two matrices
    Matrix multiply(const Matrix& other) const {
        if (cols != other.rows) {
            throw invalid_argument("Matrices are not compatible for multiplication!");
        }
        Matrix result(rows, other.cols);
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < other.cols; j++) {
                int sum = 0;
                for (int k = 0; k < cols; k++) {
                    sum += mat[i][k] * other.getValue(k, j);
                }
                result.setValue(i, j, sum);
            }
        }
        return result;
    }

    // Function to transpose the matrix
    Matrix transpose() const {
        Matrix result(cols, rows);
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                result.setValue(j, i, mat[i][j]);
            }
        }
        return result;
    }

    // Function to display the matrix
    void display() const {
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                cout << mat[i][j] << " ";
            }
            cout << endl;
        }
    }
};

int main() {
    int rows, cols;
    cout << "Enter number of rows and columns for matrix: ";
    cin >> rows >> cols;

    Matrix mat1(rows, cols);
    Matrix mat2(rows, cols);

    cout << "Enter elements for first matrix:" << endl;
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            int value;
            cin >> value;
            mat1.setValue(i, j, value);
        }
    }

    cout << "Enter elements for second matrix:" << endl;
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            int value;
            cin >> value;
            mat2.setValue(i, j, value);
        }
    }

    char choice;
    cout << "Choose operation:" << endl;
    cout << "a. Sum" << endl;
    cout << "b. Product" << endl;
    cout << "c. Transpose" << endl;
    cout << "Enter your choice: ";
    cin >> choice;

    try {
        switch (choice) {
            case 'a': {
                Matrix sum = mat1.add(mat2);
                cout << "Sum of matrices:" << endl;
                sum.display();
                break;
            }
            case 'b': {
                Matrix product = mat1.multiply(mat2);
                cout << "Product of matrices:" << endl;
                product.display();
                break;
            }
            case 'c': {
                Matrix transposeMat1 = mat1.transpose();
                Matrix transposeMat2 = mat2.transpose();
                cout << "Transpose of first matrix:" << endl;
                transposeMat1.display();
                cout << "Transpose of second matrix:" << endl;
                transposeMat2.display();
                break;
            }
            default:
                cout << "Invalid choice!" << endl;
        }
    } catch (const invalid_argument& e) {
        cout << "Exception caught: " << e.what() << endl;
    }

    return 0;
}

