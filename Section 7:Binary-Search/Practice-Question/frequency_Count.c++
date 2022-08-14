#include<bits/stdc++.h>
using namespace std;
/*****************First Function*************************/
int lowerBound(vector<int> vctr , int key)
{
    int low = 0;
    int high = vctr.size() - 1;
    int ans;
    while(low <= high)
    {
        int mid = (low + high)/2;
        if(vctr[mid] < key)
        {
            ans = mid;
            low = mid + 1;
        }
        else{
            high = mid - 1;
        }
    }
    return ans; 
}
/********************Second Function*********************/
int upperBound(vector<int> vctr , int key)
{
    int low = 0;
    int high = vctr.size() - 1;
    int ans;
    while(low <= high)
    {
        int mid = (low + high)/2;
        if(vctr[mid] > key)
        {
            ans = mid;
            high = mid - 1;
        }
        else{
            low = mid + 1;
        }
    }
    return ans; 
}
int main(int argc, char const *argv[])
{
    int n , key;
    cin>>n>>key;
    vector<int> vctr(n,0);
    for(int i=0;i<n;i++)
    {
        cin>>vctr[i];
    }
    int a = lowerBound(vctr , key);
    int b = upperBound(vctr , key);
    cout<<a<<" "<<b<<endl;
    if((a == -1 and b == -1) or (a == n and b == n))
    {
        cout<<"Answer :"<<-1<<endl;
    }
    else{
        cout<<"Answer :"<<b-(a+1)<<endl;
    }
    return 0;
}
