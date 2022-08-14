#include<bits/stdc++.h>
using namespace std;

//Helper function:
int longestPath(vector<vector<int>> &v , int i , int j , int m , int n)
{
    if(i == m-1 and j == n-1)
  {
    //   v[i][j] =2;
      return 0;
  }
  if(i>=m or j>=n or i<0 or j<0)
  {
      return -1;
  }
  if(v[i][j] == 2 or v[i][j] == 0)
  {
      return 0;
  }
  
  int a = INT_MIN;
  int b = INT_MIN;
  int c = INT_MIN;
  int d = INT_MIN;
  v[i][j] = 2;
   a = 1 + longestPath(v , i+1 , j , m , n);
  v[i][j] = 0;
  v[i][j] = 2;
   b = 1 + longestPath(v , i-1 , j , m , n);
  v[i][j] = 0;
  v[i][j] = 2;
   c = 1 + longestPath(v , i , j+1 , m , n);
  v[i][j] = 0;
  v[i][j] = 2;
   d = 1 + longestPath(v , i , j-1 , m , n);
  v[i][j] = 0;

  return max(a , max(b,max(c , d)));
}

int findLongestPath(int m, int n, vector<vector<int>> v){
    //Complete this function. Do not modify the name or parameters. You can make a helper function if needed.
    return longestPath(v , 0 , 0 , m ,n);
}
//Main 
int main(int argc, char const *argv[])
{
    int m, n;
    cin>>m>>n;
    vector<vector<int>> vctr(m , vector<int> (n , 0));
    //Initialization:
    for(int i=0;i<m;i++)
    {
        for(int j=0;j<n;j++)
        {
            cin>>vctr[i][j];
        }
    }
    //Call:
    cout<<findLongestPath(m , n , vctr)<<endl;
    return 0;
}

