#include<bits/stdc++.h>
using namespace std;

int angry_birds(int n , int b , vector<int> nest)
{
    int size = nest.size() - 1;
    int low = 0;
    int high = nest.size();
    int answer = 0;

    while(low <= high)
    {
        int mid = (low + high)/2;
        int cnt =1;
        int prev = nest[0];
        for(int i=1;i<nest.size();i++)
        {
          if(nest[i] - prev >= mid)
          {
            cnt++;
            prev = nest[i];
          }
        }
        if(cnt == b)
        {
            answer = mid;
            low = mid + 1;
        }
        else{
            high = mid - 1;
        }
    }
    return answer;
}
int main(int argc, char const *argv[])
{
    int n , b;
    cin>>n>>b;
    vector<int> nest(n,0);
    for(int i=0;i<n;i++)
    {
        cin>>nest[i];
    }
    cout<<"Answer :"<<angry_birds(n,b,nest)<<endl;

    return 0;
}
