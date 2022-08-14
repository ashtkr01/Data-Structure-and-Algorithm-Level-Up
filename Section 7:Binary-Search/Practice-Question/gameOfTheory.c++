#include<bits/stdc++.h>
using namespace std;


int getCoins(vector<int> arr, int k){
    //return the max coins that you can win!
    int n = arr.size();
    int answer = 0;
    vector<int> prefixSum(n,0);
    prefixSum[0] = arr[0];
    int minEle = arr[0];
    for(int i=1;i<n;i++)
    {
        prefixSum[i] = prefixSum[i-1] + arr[i]; 
        if(minEle > arr[i])
        {
            minEle = arr[i];
        }
    }
    int flag = 0;
    int low = minEle;
    int high = prefixSum[n-1];
    // cout<<low<<" "<<high<<endl;

    while(low <= high)
    {
        flag = 0;
        int mid = (low + high)/2;
        int prev = 0;
        int cnt =0;
        for(int i=0;i<n;i++)
        {
            if(prefixSum[i] - prev >= mid)
            {
                prev = prefixSum[i];
                cnt++;
                if(cnt == k-1)
                {
                    if(prefixSum[n-1] - prev >= mid)
                    {
                        answer = mid;
                        low = mid+1;
                        flag = 1;
                        break;

                    }
                    else{
                        high = mid - 1;
                        break;
                    }
                }
            }
        }
        if(flag != 1)
        {
            high = mid - 1;
        }

    }
    return answer;    
}
int main(int argc, char const *argv[])
{
    int n , k;
    cin>>n>>k;
    vector<int> coins(n,0);
    for(int i=0;i<n;i++)
    {
        cin>>coins[i];
    }
    cout<<"Answer :"<<getCoins(coins , k)<<endl;

    return 0;
}
