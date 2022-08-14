#include <bits/stdc++.h>
using namespace std;
//Helper Function
int maxValue(int i , int j , vector<int> v)
{
    if(i>j)
    {
        return 0;
    }
    int a = INT_MIN;
    int b = INT_MIN;
    a = v[i] + min(maxValue(i+2 , j , v) , maxValue(i+1 , j-1 , v));
    b = v[j] + min(maxValue(i+1 , j-1 , v) , maxValue(i , j-2 , v));
    return max(a , b);
}
int MaxValue(int n, vector<int> v)
{
    // Write your code here. Do not modify the function or parameters. You can use a helper function if needed.
    int i = 0;
    int j = v.size()-1;
    return maxValue(i , j , v);
}
//Main Function:
int main(int argc, char const *argv[])
{
    int n;
    cin>>n;
    vector<int> vctr(n , 0);
    //Initialization of vector:
    for(int i=0;i<n;i++)
    {
        cin>>vctr[i];
    }
    //Call:
    cout<<MaxValue(n , vctr)<<endl;
    return 0;
}
