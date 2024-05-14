/*Write a menu driven program to perform string manipulation (without using inbuilt
string functions):
a. Show address of each character in string
b. Concatenate two strings.
c. Compare two strings
d. Calculate length of the string (use pointers)
e. Convert all lowercase characters to uppercase
f. Reverse the string */
#include <iostream>
using namespace std;

// Function to show address of each character in string
void showAddress(const char* str) {
    cout << "Address of each character in the string: " << endl;
    for (int i = 0; str[i] != '\0'; i++) {
        cout << "Character: " << str[i] << ", Address: " << (void*)(&str[i]) << endl;
    }
}

// Function to concatenate two strings
void concatenateStrings(char* str1, char* str2) {
    int len1 = 0;
    while (str1[len1] != '\0') {
        len1++;
    }

    int len2 = 0;
    while (str2[len2] != '\0') {
        str1[len1 + len2] = str2[len2];
        len2++;
    }
    str1[len1 + len2] = '\0';

    cout << "Concatenated string: " << str1 << endl;
}

// Function to compare two strings
int compareStrings(const char* str1, const char* str2) {
    int i = 0;
    while (str1[i] == str2[i]) {
        if (str1[i] == '\0') {
            return 0; // Strings are equal
        }
        i++;
    }
    return str1[i] - str2[i];
}

// Function to calculate length of the string using pointers
int calculateLength(const char* str) {
    int length = 0;
    while (str[length] != '\0') {
        length++;
    }
    return length;
}

// Function to convert all lower case characters to uppercase
void convertToUpperCase(char* str) {
    int i = 0;
    while (str[i] != '\0') {
        if (str[i] >= 'a' && str[i] <= 'z') {
            str[i] -= 32; // Convert to uppercase
        }
        i++;
    }
    cout << "String in uppercase: " << str << endl;
}

// Function to reverse the string
void reverseString(char* str) {
    int length = 0;
    while (str[length] != '\0') {
        length++;
    }
    for (int i = 0; i < length / 2; i++) {
        char temp = str[i];
        str[i] = str[length - i - 1];
        str[length - i - 1] = temp;
    }
    cout << "Reversed string: " << str << endl;
}

int main() {
    char str1[100], str2[100];
    char choice;
    int position;

    cout << "Enter the first string: ";
    cin.getline(str1, 100);

    cout << "Enter the second string: ";
    cin.getline(str2, 100);

    cout << "Menu:" << endl;
    cout << "a. Show address of each character in string" << endl;
    cout << "b. Concatenate two strings" << endl;
    cout << "c. Compare two strings" << endl;
    cout << "d. Calculate length of the string" << endl;
    cout << "e. Convert all lower case characters to uppercase" << endl;
    cout << "f. Reverse the string" << endl;
    cout << "Enter your choice: ";
    cin >> choice;

    switch (choice) {
        case 'a':
            showAddress(str1);
            break;
        case 'b':
            concatenateStrings(str1, str2);
            break;
        case 'c':
            if (compareStrings(str1, str2) == 0) {
                cout << "Strings are equal" << endl;
            } else {
                cout << "Strings are not equal" << endl;
            }
            break;
        case 'd':
            cout << "Length of first string: " << calculateLength(str1) << endl;
            cout << "Length of second string: " << calculateLength(str2) << endl;
            break;
        case 'e':
            convertToUpperCase(str1);
            break;
        case 'f':
            reverseString(str1);
            break;
        default:
            cout << "Invalid choice!" << endl;
    }

    return 0;
}
