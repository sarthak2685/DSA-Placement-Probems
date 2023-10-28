#include <iostream>
#include <queue>
#include <stack>
using namespace std;

bool isQueuePalindrome(queue<char>& q) {
    stack<char> s;
    int size = q.size();
    for (int i = 0; i < size / 2; i++) {
        s.push(q.front());
        q.pop();
    }
    if (size % 2 != 0)
        q.pop();
    while (!q.empty()) {
        if (q.front() != s.top())
            return false;
        q.pop();
        s.pop();
    }
    return true;
}

int main() {
    queue<char> q;
    string input;
    cout << "Enter a string: ";
    cin >> input;

    for (char c : input) {
        q.push(c);
    }

    if (isQueuePalindrome(q))
        cout << "The string is a palindrome." << endl;
    else
        cout << "The string is not a palindrome." << endl;

    return 0;
}
