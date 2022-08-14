#include<bits/stdc++.h>
using namespace std;


int minPages(vector<int> books, int m){
  int answer = 0;
  int n = books.size();
  vector<int> prefixSum(n , 0);
  int minEle = books[0];
  prefixSum[0] = books[0];
  for(int i=1;i<n;i++)
  {
    prefixSum[i] = prefixSum[i-1] + books[i];
    if(minEle > books[i])
    {
        minEle = books[i];
    }
  }

  int flag = 0;
  int low = minEle;
  int high = prefixSum[n - 1];

  cout<<low<<" "<<high<<endl;


  while(low <= high)
  {
    int mid = (low + high)/2;
    int prev = 0;
    int cnt = 0;
    flag = 0;
   for(int i=0;i<n;i++)
   {
    if(prefixSum[i] - prev > mid)
    {
        prev = prefixSum[i - 1];
        cnt++;
        if(books[i] > mid)
        {
            low = mid + 1;
            flag = 1;
            break;
        }
        // if(cnt == m - 1)
        // {
        //     if(prefixSum[n-1] - prev <= mid)
        //     {
        //         // cout<<"Hi"<<endl;
        //         answer = mid;
        //         high = mid - 1;
        //         flag = 1;
        //         break;
        //     }
        //     else{
        //         low = mid + 1;
        //         flag = 1;
        //         break;
        //     }
        // }
    }
   }
   if(flag == 1)
   {
    low = mid + 1;

   }
   
   else if(cnt < m)
   {
    answer = mid;
    high = mid - 1;
   }
   else if(cnt >= m)
   {
    low = mid + 1;
   }
 }
  return answer;
}

int main(int argc, char const *argv[])
{
    
    int n , k;
    cin>>n>>k;
    vector<int> pages(n,0);
    for(int i=0;i<n;i++)
    {
        cin>>pages[i];
    }
    cout<<"Answer :"<<minPages(pages , k)<<endl;

    return 0;
}
