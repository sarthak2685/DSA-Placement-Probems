#include <bits/stdc++.h>
using namespace std;

int main(){
    int num;
    cout<<"Enter the number of elements in the array: ";
    cin>>num;
    int arr[num];
    cout<<"Enter the elements in the array: ";

    for(int i=0;i<num;i++){
        cin>>arr[i];
    }

    int largest=arr[0];

    for(int i=0;i<num;i++){
        if (arr[i]>largest){
            largest= arr[i];
        }
    }

    int secondLargest=INT_MIN;

    for(int i=0;i<num;i++){
        if (arr[i]!=largest && arr[i]>secondLargest){
            secondLargest = arr[i];
        }
    }



    cout<<"Second largest element in the given array is: "<<secondLargest;
    
    return 0;
}