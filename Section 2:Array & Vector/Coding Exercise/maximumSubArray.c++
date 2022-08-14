#include<bits/stdc++.h>
using namespace std;

int maxSubarraySum(vector<int> arr){
    //Complete this function, your function should return the maximum subarray sum
    int n = arr.size();
    
    int currMaxSubArray = 0;
    int maxSubArray = INT_MIN;
    
    //Iterate over loop:
    for(int i=0;i<n;i++)
    {
        currMaxSubArray += arr[i];
        if(currMaxSubArray >= maxSubArray)
        {
            maxSubArray = currMaxSubArray;
        }
        if(currMaxSubArray < 0)
        {
            currMaxSubArray = 0;
        }
    }

    return maxSubArray;
}
//Main Function:
int main(int argc, char const *argv[])
{
    int n;
    cin>>n;
    vector<int> vctr(n,0);
    //Initialisation of vector:
    for(int i=0;i<n;i++)
    {
        cin>>vctr[i];
    }
    int res = maxSubarraySum(vctr);
    cout<<res<<endl;
    return 0;
}
