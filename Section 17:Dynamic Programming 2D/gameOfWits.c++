#include <bits/stdc++.h>
using namespace std;
/*******************************First Approach****************************************************/
// Helper
pair<char, int> gameOfWits(string s, int sts, int end, int chance , vector<vector<vector<pair<char,int>>>> &dp )
{
    if (sts > end and chance == 0)
    {
        return dp[sts][end][chance] = {'H', 1};
    }
    else if (sts > end and chance == 1)
    {
        return dp[sts][end][chance] = {'O', 1};
    }
    else if (s[sts] == 'O' and s[end] == 'O' and chance == 1)
    {
        return dp[sts][end][chance] = {'O', end - sts + 2};
    }
    else if (s[sts] == 'H' and s[end] == 'H' and chance == 0)
    {
        return dp[sts][end][chance] = {'H', end - sts + 2};
    }
    else if(dp[sts][end][chance].second != -1)
    {
        return dp[sts][end][chance];
    }
    else if (chance == 0)
    {
        if (s[sts] == 'O' and s[end] == 'O')
        {
            pair<char, int> pr1 = gameOfWits(s, sts + 1, end, 1, dp);
            pair<char, int> pr2 = gameOfWits(s, sts, end - 1, 1, dp);
            if (pr1.first == 'O' and pr2.first == 'O')
            {
                return dp[sts][end][chance] =  pr1.second > pr2.second ? pr1 : pr2;
            }
            else if (pr1.first == 'O')
            {
                return dp[sts][end][chance] =  pr1;
            }
            else if (pr2.first == 'O')
            {
                return dp[sts][end][chance] =  pr2;
            }
            else
            {
                return dp[sts][end][chance] =  pr1.second > pr2.second ? pr1 : pr2;
            }
        }
        else if (s[sts] == 'O')
        {
            pair<char, int> pr1 = gameOfWits(s, sts + 1, end, 1 , dp);
            return dp[sts][end][chance] =  pr1;
        }
        else if (s[end] == 'O')
        {
            pair<char, int> pr1 = gameOfWits(s, sts, end - 1, 1 , dp);
            return dp[sts][end][chance] =  pr1;
        }
    }
   else if (chance == 1)
    {
        if (s[sts] == 'H' and s[end] == 'H')
        {
            pair<char, int> pr1 = gameOfWits(s, sts + 1, end, 0 , dp);
            pair<char, int> pr2 = gameOfWits(s, sts, end - 1, 0 , dp);
            if (pr1.first == 'H' and pr2.first == 'H')
            {
                return dp[sts][end][chance] =  pr1.second > pr2.second ? pr1 : pr2;
            }
            else if (pr1.first == 'H')
            {
                return dp[sts][end][chance] =  pr1;
            }
            else if (pr2.first == 'H')
            {
                return dp[sts][end][chance] =  pr2;
            }
            else
            {
                return dp[sts][end][chance] =  pr1.second > pr2.second ? pr1 : pr2;
            }
        }
        else if (s[sts] == 'H')
        {
            pair<char, int> pr1 = gameOfWits(s, sts + 1, end, 0 , dp);
            return dp[sts][end][chance] = pr1;
        }
        else if (s[end] == 'H')
        {
            pair<char, int> pr1 = gameOfWits(s, sts, end - 1, 0 , dp);
            return dp[sts][end][chance] = pr1;
        }
    }
}
pair<char, int> GameOfWits(string s)
{
    // Write your code here. Do not modify the function or parameters. Use a helper function if needed.
    pair<char , int> ps;
    int lastIdx = s.size()-1;
    int n = s.size();
 vector<vector<vector<pair<char,int>>>> dp( n ,vector<vector<pair<char,int>>>( n,vector<pair<char,int>>( 2,{' ',-1})));
// x = number of elements in 1D vector
// y = number of 1D vectors in 2D vector
// z = number of 2D vectors in 3D vector
// value = value for each element

    cout<<lastIdx<<endl;
    return gameOfWits(s , 0 , lastIdx , 0 , dp) ;
  
}
//Main
int main(int argc, char const *argv[])
{
    pair<char , int > pr;
    string str;
    cin>>str;
    //Call:
    pr = GameOfWits(str);
    cout<<pr.first<<"----"<<pr.second<<endl;
    return 0;
}
