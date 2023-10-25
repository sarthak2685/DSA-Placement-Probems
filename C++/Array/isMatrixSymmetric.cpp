// Check Symmetric matrix in C++

#include <bits/stdc++.h>
using namespace std;

int main()
{
    int r, c;
    cout << "Please input the matrix rows: ";
    cin >> r;
    cout << "Please input the matrix columns: ";
    cin >> c;
    cout << "Please give the value of each cell of the matrix one by one below" << endl;
    int a[r][c];
    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < c; j++)
        {
            cin >> a[i][j];
        }
    }
    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < c; j++)
        {
            if (a[i][j] != a[j][i])
            {
                cout << "Matrix is asymmetric" << endl;
                return 0;
            }
        }
    }
    cout << "Matrix is Symmetric" << endl;
    return 0;
}
