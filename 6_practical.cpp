/*Write a program to search a given element in a set of N numbers using Binary search
(i) with recursion (ii) without recursion*/

//i) with recursion

#include <iostream>
using namespace std;

// Recursive function for binary search
int binarySearchRecursive(int arr[], int low, int high, int key) {
    if (low <= high) {
        int mid = low + (high - low) / 2;

        // If the key is found at the middle
        if (arr[mid] == key) {
            return mid;
        }

        // If the key is smaller than the middle element, search in the left subarray
        if (arr[mid] > key) {
            return binarySearchRecursive(arr, low, mid - 1, key);
        }

        // If the key is larger than the middle element, search in the right subarray
        return binarySearchRecursive(arr, mid + 1, high, key);
    }

    // If the key is not present in the array
    return -1;
}

int main() {
    // Initialize the array directly
    int arr[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int n = sizeof(arr) / sizeof(arr[0]); // Calculate the size of the array

    int key;
    cout << "Enter the element to search: ";
    cin >> key;

    int index = binarySearchRecursive(arr, 0, n - 1, key);

    if (index != -1) {
        cout << "Element found at index: " << index << endl;
    } else {
        cout << "Element not found in the array." << endl;
    }

    return 0;
}




// ii) without recursion

#include <iostream>
using namespace std;

// Function for binary search
int binarySearch(int arr[], int n, int key) {
    int low = 0, high = n - 1;

    while (low <= high) {
        int mid = low + (high - low) / 2;

        // If the key is found at the middle
        if (arr[mid] == key) {
            return mid;
        }

        // If the key is smaller than the middle element, search in the left subarray
        if (arr[mid] > key) {
            high = mid - 1;
        }

        // If the key is larger than the middle element, search in the right subarray
        else {
            low = mid + 1;
        }
    }

    // If the key is not present in the array
    return -1;
}

int main() {
    // Initialize the array directly
    int arr[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int n = sizeof(arr) / sizeof(arr[0]); // Calculate the size of the array

    int key;
    cout << "Enter the element to search: ";
    cin >> key;

    int index = binarySearch(arr, n, key);

    if (index != -1) {
        cout << "Element found at index: " << index << endl;
    } else {
        cout << "Element not found in the array." << endl;
    }

    return 0;
}
