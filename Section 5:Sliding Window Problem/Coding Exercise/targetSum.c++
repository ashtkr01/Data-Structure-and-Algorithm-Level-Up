#include<bits/stdc++.h>
using namespace std;



int cntSubarrays(vector<int> arr,int k){
    //complete this method
    unordered_map<int , int> ump;
    int count = 0;
    ump[0] =1;
    int length = arr.size();
    for(int i=1;i<length;i++)
    {
      arr[i] = arr[i-1] + arr[i];
    }
    //Traverse the array :
    for(int i=0;i<length;i++)
    {
        if(ump.find(arr[i] - k) != ump.end())
        {
          count += ump[arr[i] -k];
        }
        ump[arr[i]]++;
    }
    return count;
}
//Main :
int main(int argc, char const *argv[])
{
    int n , k;
    cin>>n>>k;
    vector<int> vctr(n , 0);
    //INitialisation :
    for(int i=0;i<n;i++)
    {
        cin>>vctr[i];
    }
    cout<<cntSubarrays(vctr , k)<<endl;
    return 0;
}
