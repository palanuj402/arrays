
// C++ program for product array puzzle
// with O(n) time and O(1) space.
#include <bits/stdc++.h>
using namespace std;

// Solve function which prints the answer
void solve(int arr[], int n)
{
    // Initialize a variable to store the
    // total product of the array elements
    int prod = 1;
    for (int i = 0; i < n; i++)
        prod *= arr[i];

    // we know x/y mathematically is same
    // as x*(y to power -1)
    for (int i = 0; i < n; i++)
        cout << prod * (int)pow(
                           arr[i], -1)
             << " ";
}

// Driver Code
int main()
{
    int arr[] = { 10, 3, 5, 6, 2 };
    int n = sizeof(arr) / sizeof(arr[0]);
    solve(arr, n);
    return 0;
}

