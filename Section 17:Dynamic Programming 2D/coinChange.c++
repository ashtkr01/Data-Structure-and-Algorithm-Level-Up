#include<bits/stdc++.h>
using namespace std;

//Helper Function :
long long findCombination(int n, int st , vector<int> coins , vector<vector<int>> &dp){
    //Write your code here. Do not modify the function or parameters. You can use helper function if needed.
    if(n == 0)
    {
        return 1;
    }
    if(dp[n][st] != -1)
    {
        return dp[n][st];
    }
    long long ans = 0;
    // long long ans2 = 0;
    //Loop :
    for(int i = st;i<coins.size();i++)
    {
        if( n - coins[i] >= 0)
        {
            ans += findCombination(n-coins[i], i , coins , dp ) ;
            
        }
    }
    return dp[n][st] = ans ;
}

long long findCombinations(int n, vector<int> coins){
    //Write your code here. Do not modify the function or parameters. You can use helper function if needed.
    int size = coins.size();
    vector<vector<int>> dp( n + 1 , vector<int>(size ,-1));
    return findCombination(n , 0 , coins , dp);
}
//Main Function:
int main(int argc, char const *argv[])
{
    int n , val;
    cin>>n>>val;
    int ele;
    vector<int> coins(n , 0);
    for(int i=0;i<n;i++)
    {
        cin>>coins[i];
    }
    //Call to the main function:
    cout<<findCombinations(val , coins)<<endl;
    
    return 0;
}
