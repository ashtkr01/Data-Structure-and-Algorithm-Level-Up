#include<bits/stdc++.h>
using namespace std;
/****************************First Approach***************************/
int rainFun(vector<int> vctr , int n)
{
    vector<int> left(n,0);
    vector<int> right(n,0);
    vector<int> res(n,0);

    right[n-1] = vctr[n-1];
    left[0] = vctr[0];

    for(int i = n-2;i>=0;i--)
    {
        right[i] = max(right[i+1] , vctr[i]); 
    }

    for (auto x : right)
    {
        cout<<x<<" ";
    }
    cout<<endl;

    for(int i=1;i<n;i++)
    {
        left[i] = max(vctr[i] , left[i-1]);
    }

    for (auto x : left)
    {
        cout<<x<<" ";
    }
    cout<<endl;

    for(int i=0;i<n;i++)
    {
        int a = min(left[i] , right[i]) - vctr[i];
        if(a >= 0)
        {
            res[i] = a;
        }
    }
    for (auto x : res)
    {
        cout<<x<<" ";
    }
    cout<<endl;


}
int main(int argc, char const *argv[])
{
    int n;
    cin>>n;
    vector<int> vctr(n , 0);
    for(int i=0;i<n;i++)
    {
        cin>>vctr[i];
    }

    cout<<"Answer :"<<rainFun(vctr , n)<<endl;

    return 0;
}
