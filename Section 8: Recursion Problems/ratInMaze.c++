#include <bits/stdc++.h>
using namespace std;

// Helper function
bool path(vector<vector<char>> &c, int i, int j, int row)
{
    if (i >= row or j >= row)
    {
        return false;
    }
    if (i == row - 1 and j == row - 1)
    {
        // Copy in another vecrtor:
        //  print:
        c[i][j] = '*';
        for (int x = 0; x < row; x++)
        {
            for (int y = 0; y < row; y++)
            {
                cout << c[x][y] << "    ";
            }
            cout << endl;
        }
        return true;
    }
    if (c[i][j] != 'X')
    {
        c[i][j] = '*';
        bool res = path(c, i, j + 1, row);
        if (res)
        {
            return true;
        }
        else if (!res)
        {
            c[i][j] = 'O';
            //  return false;
        }
    }
    if (c[i][j] != 'X')
    {
        c[i][j] = '*';
        if (path(c, i + 1, j, row))
        {
            return true;
        }
        else
        {
            c[i][j] = 'O';
            // return false;
        }
    }
    return false;
}
vector<int> findPath(int n, vector<vector<char>> c)
{
    ////Write your code below. Do not modify this function or parameters. You can use helper function if needed.
    vector<int> vctr;
    if (n >= 1)
    {
        int count = 0;
        c[0][0] = '*';
        int i = 0;
        int j = 0;
        int row = c.size();
        path(c, i, j, row);
        // fILL THE RESULTANT VECTOR:
        for(int x = 0;x<row;x++)
        {
            for(int y=0;y<row;y++)
            {
                count++;
                if(c[x][y]=='*')
                {
                    vctr.push_back(count);
                }
            }
        }
        // REturn
        return vctr;
    }
    return vctr;
}
// Main
int main(int argc, char const *argv[])
{
    vector<int> result;
    int n;
    cin >> n;
    // Initialization of vector:
    vector<vector<char>> ch(n, vector<char>(n, 'O'));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> ch[i][j];
        }
    }
    // Call:
    result = findPath(n, ch);
    // Print :
    for (auto x : result)
    {
        cout << x << "  ";
    }
    cout << endl;
    return 0;
}
