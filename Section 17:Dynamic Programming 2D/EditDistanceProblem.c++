#include <bits/stdc++.h>
using namespace std;
#define max 10000
// Helper Function:
int editdistance(string str1, int i, int j, string str2, int x, int y )
{
    if (i == j + 1 and x == y + 1)
    {
        // cout<<"Hello"<<endl;
        return 0;
    }
    else if ((i == j and x == y) and (str1[i] == str2[x]))
    {
        return 0;
    }
    else if ((i == j and x != y) or (x == y and i != j))
    {
        return max;
    }
    // if(dp[i][x] != -1)
    // {
    //     return dp[i][x];
    // }
    if (str1[i] == str2[x])
    {
        return editdistance(str1, i + 1, j, str2, x + 1, y );
    }
    int a = max;
    int b = max;
    int c = max;
    // 1->Replace:
    char d = str1[i];
    str1[i] = str2[x];
    // cout<<str1<<"----"<<str2<<endl;
    a = 1 + editdistance(str1, i + 1, j, str2, x + 1, y );
    // cout<<a<<endl;
    str1[i] = d;
    // cout<<str1<<"----"<<str2<<endl;
    // 2->remove
    str1.erase(i, 1);
    // cout<<str1<<"----"<<str2<<endl;
    b = 1 + editdistance(str1, i, j - 1, str2, x, y );
    // cout<<b<<endl;
    str1.insert(i, 1, d);
    // cout<<str1<<"----"<<str2<<endl;
    // 3->insert:
    str1.insert(i, 1, str2[x]);
    // cout<<str1<<"----"<<str2<<endl;
    c = 1 + editdistance(str1, i + 1, j + 1, str2, x + 1, y );
    // cout<<c<<endl;
    str1.erase(i, 1);
    // cout<<str1<<"----"<<str2<<endl;
    return min(a, min(b, c));
}
int editDistance(string str1, string str2)
{
    // Write your code here. Do not modify the function or the parameters. You can use helper function if needed.
    int i = 0;
    int j = str1.length() - 1;
    int x = 0;
    int y = str2.length() - 1;
    
        // vector<vector<int>> dp(2*y , vector<int> (2*y , -1));
    
    
    // cout << j << "  " << y << endl;
    return editdistance(str1, i, j, str2, x, y);
}
// Main:
int main(int argc, char const *argv[])
{
    string str1, str2;
    cin >> str1 >> str2;
    // Call to the main function:
    cout << "Answer : " << editDistance(str1, str2) << endl;
    return 0;
}
