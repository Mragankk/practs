/*Write a program to merge two ordered arrays to get a single ordered array.*/
##include <iostream>
using namespace std;

// Function to merge two ordered arrays into a single ordered array
void mergeArrays(int arr1[], int m, int arr2[], int n, int merged[]) {
    int i = 0, j = 0, k = 0;

    // Traverse both arrays and compare elements
    while (i < m && j < n) {
        if (arr1[i] < arr2[j]) {
            merged[k++] = arr1[i++];
        } else {
            merged[k++] = arr2[j++];
        }
    }

    // Copy remaining elements of arr1, if any
    while (i < m) {
        merged[k++] = arr1[i++];
    }

    // Copy remaining elements of arr2, if any
    while (j < n) {
        merged[k++] = arr2[j++];
    }
}

int main() {
    int m, n;

    cout << "Enter the size of first array: ";
    cin >> m;
    int arr1[m];
    cout << "Enter the elements of first array in ascending order: ";
    for (int i = 0; i < m; i++) {
        cin >> arr1[i];
    }

    cout << "Enter the size of second array: ";
    cin >> n;
    int arr2[n];
    cout << "Enter the elements of second array in ascending order: ";
    for (int i = 0; i < n; i++) {
        cin >> arr2[i];
    }

    // Merge arrays
    int merged[m + n];
    mergeArrays(arr1, m, arr2, n, merged);

    // Print the merged array
    cout << "Merged array: ";
    for (int i = 0; i < m + n; i++) {
        cout << merged[i] << " ";
    }
    cout << endl;

    return 0;
}

