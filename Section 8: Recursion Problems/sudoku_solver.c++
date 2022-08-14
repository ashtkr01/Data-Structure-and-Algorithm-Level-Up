#include <bits/stdc++.h>
using namespace std;
// Global vector :
vector<vector<int>> vctr(9, vector<int>(9, 0));

// Return vector i.e. answer :
void makeVector(vector<vector<int>> &input, int row, int col)
{
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            vctr[i][j] = input[i][j];
        }
    }
}
// Function to check whether cell is safe or not :

// bool safe(vector<vector<int>> v, int i, int j, int num){
//     for (int x=0; x<9; x++)
// 	{
// 		if(v[x][j]==num || v[i][x]==num)
// 			return false;
// 	}

// 	for(int m = (i/3)*3; m < ((i/3)*3)+3; m++)
// 	{
// 		for(int n = (j/3)*3; n < ((j/3)*3)+3; n++)
// 		{
// 			if(v[m][n] == num)
// 				return false;
// 		}
// 	}
// 	return true;

//     }

bool safe(vector<vector<int>> &input, int i, int j, int val, int row, int col)
{
    // check in row
    for (int k = 0; k < col; k++)
    {
        if (input[i][k] == val)
        {
            return false;
        }
    }
    // check in cloumn
    for (int k = 0; k < row; k++)
    {
        if (input[k][j] == val)
        {
            return false;
        }
    }
    // Check a segment:
    int m = sqrt(row);
    int n = sqrt(col);
    int strtRow = (i / m) * m;
    int strtCol = (j / n) * n;
    for (int x = strtRow; x < (strtRow + m); x++)
    {
        for (int y = strtCol; y < (strtCol + n); y++)
        {
            if (input[x][y] == val)
            {
                return false;
            }
        }
    }
    return true;
}
// Helper function
void sudoku(vector<vector<int>> &input, int i, int j, int row, int col)
{

    if (i >= row)
    {
        cout << "Ashish :" << endl;
        // Make a return vector:
        makeVector(input, row, col);
        return;
    }
    else if (j >= col)
    {
        cout << i << "  " << j << endl;
        // cout << "Hi--" << endl;
        sudoku(input, i + 1, 0, row, col);
        return;
    }
    for (int k = 1; k <= 9; k++)
    {

        int val = k;
        if (input[i][j] == 0)
        {
            if (safe(input, i, j, val, row, col))
            {
                // cout<<"hello"<<endl;
                input[i][j] = val;
                sudoku(input, i, j + 1, row, col);
                input[i][j] = 0;
            }
        }
        else
        {
            sudoku(input, i, j + 1, row, col);
            return;
        }
    }
}

vector<vector<int>> solveSudoku(vector<vector<int>> input)
{
    int i = 0;
    int j = 0;
    int row = input.size();
    int col = input[0].size();
    cout << row << endl;
    cout << col << endl;
    sudoku(input, i, j, row, col);
    // // Print
    // for (int x = 0; x < row; x++)
    // {
    //     for (int y = 0; y < col; y++)
    //     {
    //         cout << vctr[x][y] << "  ";
    //     }
    //     cout << endl;
    // }

    return vctr;
}
// Main
int main(int argc, char const *argv[])
{
    int row, col;
    cin >> row >> col;
    vector<vector<int>> input(row, vector<int>(col, 0));
    vector<vector<int>> res(row, vector<int>(col, 0));
    // Initialization of vector:
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            cin >> input[i][j];
        }
    }
    res = solveSudoku(input);
    return 0;
}
