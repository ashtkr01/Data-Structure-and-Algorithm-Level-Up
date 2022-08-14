#include<bits/stdc++.h>
using namespace std;
//Calculate:
long long calculateSmoke(vector<int> v , int i , int k , int j )
{
    long long color1 =0;
    long long color2 = 0;
    for(int x=i;x<=k;x++)
    {
        color1 = (color1 + v[x])%100;
    }
    color1 = color1%100;
    for(int x=k+1;x<=j;x++)
    {
        color2 = (color2 + v[x]) %100;
    }
     color1 = color1%100;
     color2 = color2%100;
     return (color1*color2);

}
//Helper Function:
long long minimumsmoke(vector<int> v , int i , int j , vector<vector<int>> &dp)
{
    if( i>=j )
    {
        return 0;
    }
    if(dp[i][j] != -1)
    {
        return dp[i][j];
    }
    long long smoke = INT_MAX;
    for(int k = i;k<j;k++)
    {
        smoke = min(smoke , minimumsmoke(v, i , k ,dp) + minimumsmoke(v , k+1 , j , dp) + calculateSmoke(v , i ,k, j));
    }
    return dp[i][j] = smoke;
}
long long minimumSmoke(vector<int> v){
    //Write your code here. Do not modify the function or parameters. You can use a helper function if needed.
    int i =0;
    int j = v.size();
    vector<vector<int>> dp(j+1 , vector<int>(j+1 , -1));
    return minimumsmoke(v , i , j-1 ,dp);
}
//Main:
int main(int argc, char const *argv[])
{
    int n;
    cin>>n;
    vector<int> vctr(n,0);
    for(int i=0;i<n;i++)
    {
        cin>>vctr[i];
    }
    //Call:
    cout<<"Answer :"<<minimumSmoke(vctr)<<endl;
    return 0;
}
