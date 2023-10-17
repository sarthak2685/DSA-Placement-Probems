// BRUTE FORCE SOLUTION UISNG RECURSION

#include <bits/stdc++.h>
using namespace std;

int rangeSum(int arr[], int s, int e) {
    return accumulate(arr + s, arr + e, 0);
}

// int brute Force
int allocatePages(int arr[], int n, int k) {
    
    if (k == 1)
        return rangeSum(arr, 0, n);
    if (n == 1)
        return arr[0];

    int res = INT_MAX;
    // where should i split the arr
    for (int i=1; i<n; i++) {
        // 10 | 20 30 40
        // 10 20 | 30 40
        // 10 20 30 | 40
        res = min( res, max( rangeSum(arr, i, n), allocatePages(arr, i, k-1) ) );
    }
    return res;
}

int main()
{
    int arr[] = {10,20,30,40};
    int n = sizeof(arr)/sizeof(arr[0]);
    int k = 2;

    cout << allocatePages(arr, n, k) << endl;
    
    return 0;
}

// OPTIMAL SOLUTION 
#include <bits/stdc++.h>
using namespace std;

bool isFeasisible(int arr[], int n, int k, int pages) {
    int student = 1;
    int new_pages = 0;
    for (int i = 0; i < n; i++)
    {
        // current_pages
        if (new_pages + arr[i] <= pages) {
            new_pages += arr[i];
        }
        else {
            student++;
            new_pages = 0;
            new_pages += arr[i];
        }
    }
    return student <= k;
}

// optimal
int allocatePages(int arr[], int n, int k) {

    if (k > n)
        return -1;

    int mx = *max_element(arr, arr + n); // max
    int sum = accumulate(arr, arr + n, 0); // total Sum 
    
    int low = mx;
    int high = sum;
    int pages = 0;

    while (low <= high) {
        int mid = low + (high - low)/2;

        if (isFeasisible(arr, n, k, mid)) {
            pages = mid;
            high = mid - 1;
        }
        else 
            low = mid + 1;
    }
    return pages;
}

int main()
{
    int arr[] = {10,20,30,40};
    int n = sizeof(arr)/sizeof(arr[0]);
    int k = 2;

    cout << allocatePages(arr, n, k) << endl;
    
    return 0;
}
