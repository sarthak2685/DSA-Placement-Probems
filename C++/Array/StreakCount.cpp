/* Problem: 
CodeChef offers a feature called streak count. A streak is maintained if you solve at least one problem daily.Om and Addy actively maintain their streaks on CodeChef. Over a span of 
N consecutive days, you have observed the count of problems solved by each of them.Your task is to determine the maximum streak achieved by Om and Addy and find who had the longer maximum streak.
Input Format
The first line of input will contain a single integer T, denoting the number of test cases.
Each test case consists of multiple lines of input.
The first line of each test case contains an integer N — the number of days.
The second line of each test case contains N space-separated integers, the ℎ ith of which is A i, representing the problems solved by Om on the ℎ i th day.
The third line of each test case contains N space-separated integers, the ℎ i th of which is B i, representing the problems solved by Addy on the ℎ i thday.
Output Format
For each test case, output:
OM, if Om has longer maximum streak than Addy;
ADDY, if Addy has longer maximum streak than Om;
DRAW, if both have equal maximum streak.
You may print each character in uppercase or lowercase. For example, OM, om, Om, and oM, are all considered the same.*/

// Solution:
#include <iostream>
using namespace std;

int main() {
    int n,p,count,count1,countt,countt1;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        count =0;
        count1=0;
        countt=0;
        countt1=0;
        p=0;
        cin >> p;
        int arr[p],brr[p];
        for (int j = 0; j < p; j++)
        {
            cin >> arr[j];
        }
        for (int k = 0; k < p; k++)
        {
            cin >> brr[k];
        }

        for (int a = 0; a < p; a++)
        {
            if(arr[a]!=0){
                count++;
                continue;
            }
            else{
                if(count > count1){
                count1 = count;
                count = 0;
                }
                else{
                   count = 0; 
                }
            }
        }
            
        if(count<count1)
        count = count1;
        
        for (int b = 0; b < p; b++)
        {
            if(brr[b]!=0){
                countt++;
                continue;
            }
            else{
                if(countt > countt1){
                countt1 = countt;
                countt = 0;
                }
                else{
                   countt = 0; 
                }
            }
            
        }
        if(countt<countt1)
        countt = countt1;
        
        if(count > countt){
            cout << "Om" << endl;
        }
        else if(countt > count){
            cout << "Addy" << endl;
        }
        else{
            cout << "Draw" << endl;
        }
        
    }
    
	return 0;
}
