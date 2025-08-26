#include <bits/stdc++.h>
using namespace std;

// Function to check if both arrays are equal
bool checkArrays(int arr1[], int arr2[],
                 int n, int m)
{
    // If lengths of arrays are not equal
    if (n != m)
        return false;

    // Store arr1[] elements and
    // their frequencies in hash map
    unordered_map<int, int> mp;
    for (int i = 0; i < n; i++)

        mp[arr1[i]]++;

    // Traverse arr2[] elements and
    // check if all elements of arr2[] are
    // present same number of times or not.
    for (int i = 0; i < n; i++) {

        // If there is an element in arr2[],
        // but not in arr1[]
        if (mp.find(arr2[i]) == mp.end())
            return false;

        // If an element of arr2[] appears
        // more times than it appears in arr1[]
        if (mp[arr2[i]] == 0)
            return false;

        // Decrease the count of arr2 elements
        // in the unordered map
        mp[arr2[i]]--;
    }
    return true;
}

// Driver Code
int main()
{
    int arr1[] = { 1, 2, 3, 4, 5 };
    int arr2[] = { 4, 3, 1, 5, 2 };
    int N = sizeof(arr1) / sizeof(int);
    int M = sizeof(arr2) / sizeof(int);

    // Function call
    if (checkArrays(arr1, arr2, N, M))
        cout << "Equal";
    else
        cout << "Not Equal";
    return 0;
}
