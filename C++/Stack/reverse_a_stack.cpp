// reverse a stack (GFG)

// problem statement: Given a stack of integers St. You are required to reverse the stack using recursion. You are not allowed to use loop constructs like while, for..etc, Return St after reversing it using recursion.

// input: 1 2 3 4 5
// output: 5 4 3 2 1
// explanation: After reversing the given stack , elements are as 5 4 3 2 1.

#include <bits/stdc++.h>
using namespace std;
void insertAtbottom(stack<int> &St, int target)
{
    if (St.empty())
    {
        St.push(target);
        return;
    }

    int temp = St.top();
    St.pop();
    insertAtbottom(St, target);
    St.push(temp);
}
void Reverse(stack<int> &St)
{
    // Brute Force approach
    // vector<int> v;
    // while (St.size()) {
    //     v.push_back(St.top());
    //     St.pop();
    // }
    // for (auto it : v) {
    //     St.push(it);
    // }

    // Using Recursion
    if (St.empty())
    {
        return;
    }

    int target = St.top();
    St.pop();
    Reverse(St);
    insertAtbottom(St, target);
}
int main()
{
    int n;
    cin >> n;
    stack<int> st;
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        st.push(x);
    }
    Reverse(st);
    cout << "Printing Stack from Top to Bottom" << endl;
    while (st.size())
    {
        cout << st.top() << " ";
        st.pop();
    }
    return 0;
}