#include <iostream>
using namespace std;
int main(){
    int m ;
    int x; // target value to be found in the array 
    cout<<"enter number of elements in array \n";
    cin>>m;
     int n[m];

cout<<"enter element "<<endl;

for(int i=0;i<m;i++){
        cout<<"n["<<i<<"]="<<endl;
         cin>>n[i];
}
int length= sizeof(n) / sizeof(n[0]);
int ho=0;
int hi=length-1;
//cout<<length<<endl;
cout<< "enter target value \n";
cin>> x; 
while (ho<=hi){
    int mid;
    mid=(ho+hi)/2;
    //cout<<n[mid];
    if(n[mid]==x){
        cout<<"target is at "<<mid;
    }
    if(n[mid]>x){
        hi=mid-1;
    }
    else{
        ho=mid+1;
    }
}
return 0;
}