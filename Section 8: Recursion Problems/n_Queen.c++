#include <bits/stdc++.h>
using namespace std;
// Global Variable :
int cnt ;
unordered_set<int> ccol;
unordered_set<int> ldia;
unordered_set<int> rdia;

// Function to check
bool isItSafe(int row, int col, int n)
{
    if (ccol.find(col) != ccol.end())
    {
        return false;
    }
    if (ldia.find(n - 1 + (row - col)) != ldia.end())
    {
        return false;
    }
    if (rdia.find((row + col)) != rdia.end())
    {
        return false;
    }
    return true;
}
// Helper Function:
void nqueen(vector<vector<int>> &vctr, int curr_row, int n)
{
    if (curr_row >= n)
    {
        cnt++;
        return;
    }
    // Loop:
    for (int i = 0; i < n; i++)
    {
        if (isItSafe(curr_row, i, n))
        {
            vctr[curr_row][i] = 1;
            ccol.insert(i);
            ldia.insert(n -1 + (curr_row - i));
            rdia.insert(curr_row + i);
            nqueen(vctr, curr_row + 1, n);
            ccol.erase(i);
            ldia.erase(n-1 + (curr_row - i));
            rdia.erase(curr_row + i);
            vctr[curr_row][i] = 0;
        }
    }
}
int nQueen(int n)
{
    // Write your code below. Do not modify this function or parameters. You can use helper function if needed.
    vector<vector<int>> vctr(n, vector<int>(n, 0));
    cnt = 0;
    nqueen(vctr , 0 , n);
    return cnt;
}
//Main:
int main(int argc, char const *argv[])
{
    int n;
    cin>>n;
    cout<<"Answer :"<<nQueen(n)<<endl;
    return 0;
}
