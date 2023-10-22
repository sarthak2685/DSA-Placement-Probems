//merge two sorted arrays

//problem statement: Given two sorted arrays arr1[] of size N and arr2[] of size M. Each array is sorted in non-decreasing order. Merge the two arrays into one sorted array in non-decreasing order.

//input: N = 4, M = 5, arr1[] = {1, 3, 5, 7}, arr2[] = {0, 2, 6, 8, 9}
//output: 0 1 2 3 5 6 7 8 9

#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n,m;
    cin>>n>>m;
    int arr1[n],arr2[m];
    for(int i=0;i<n;i++)
    {
        cin>>arr1[i];
    }
    for(int i=0;i<m;i++)
    {
        cin>>arr2[i];
    }
    int i=0,j=0;
    while(i<n && j<m)
    {
        if(arr1[i]<=arr2[j])
        {
            cout<<arr1[i]<<" ";
            i++;
        }
        else
        {
            cout<<arr2[j]<<" ";
            j++;
        }
    }
    while(i<n)
    {
        cout<<arr1[i]<<" ";
        i++;
    }
    while(j<m)
    {
        cout<<arr2[j]<<" ";
        j++;
    }
    
    return 0;
}