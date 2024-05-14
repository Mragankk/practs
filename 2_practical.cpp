/* Write a program to remove the duplicates from an array.*/
#include <iostream>
#include <vector>
#include <set>

using namespace std;
int main()
{
    vector<int> arr = {1, 2, 4, 5, 6, 6, 4, 3, 2, 6, 7, 9, 0};
    set<int> s(arr.begin(), arr.end());
    arr.assign(s.begin(), s.end());

    for (int i : arr)
    {
        cout << i << " ";
    }
    return 0;
}

