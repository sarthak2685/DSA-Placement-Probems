// make palindrome (GFG)

// problem statement: You are given an array of strings arr of size n. You have to find out if it is possible to make a palindromic string by concatenating all the strings in any order. Provided that all the strings given in the array are of equal length.

// input: n = 4, arr = {"djfh", "gadt", "hfjd", "tdag"}
// output : Yes
// explanation: By concatenating all the strings in the array, we can get a palindromic string "djfhgadthfjdtdag".

// input: n = 3, arr = {"abc", "def", "ghi"}
//  output: No
//  explanation: By concatenating all the strings in the array, we can't get a palindromic string.

#include <bits/stdc++.h>
using namespace std;
bool makePalindrome(int n, vector<string> &arr)
{
    sort(arr.begin(), arr.end());
    vector<string> arrc;
    for (int i = 0; i < n; i++)
    {
        string str = arr[i];
        reverse(str.begin(), str.end());
        arrc.push_back(str);
    }
    sort(arrc.begin(), arrc.end());
    return arr == arrc;
}
int main()
{
    int n;
    cin >> n;
    vector<string> arr(n);
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    if (makePalindrome(n, arr))
        cout << "Yes" << endl;
    else
        cout << "No" << endl;
    return 0;
}