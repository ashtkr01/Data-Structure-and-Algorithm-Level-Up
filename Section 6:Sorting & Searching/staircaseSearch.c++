#include<bits/stdc++.h>
using namespace std;
pair<int,int> search(int m, int n, vector<vector<int>> v, int k){
    //write your code here.
    pair<int , int > pr;
     int i=0;
     int j = n-1;
     while(i<m and j>=0)
     {
         if( k == v[i][j])
         {
            //  cout<<"Hi"<<endl;
             pr.first = i;
             pr.second = j;
             return pr;
         }
         else if(k < v[i][j])
         {
             j--;
             continue;
         }
         else if(k > v[i][j])
         {
             i++;
             continue;
         }
     }
     pr.first = -1;
     pr.second = -1;
     return pr;
}
//Main :
int main(int argc, char const *argv[])
{
    int m , n , k;
    cin>>m>>n>>k;
    vector<vector<int >> vctr( m , vector<int> ( n , 0 ));
    pair<int ,int> pr;
    //Initialisation of vector :
    for(int i=0;i<m;i++)
    {
        for(int j=0;j<n;j++)
        {
            cin>>vctr[i][j];
        }
    }
    pr = search(m , n , vctr , k);
    cout<<"Answer : "<<pr.first<<"   "<<pr.second<<endl;
    return 0;
}
