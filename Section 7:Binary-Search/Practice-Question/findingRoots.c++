#include<bits/stdc++.h>
using namespace std;

double findingRoots(int n , int p)
{
    int low = 0;
    int high = n;
    double ans = 0;
    while(low <= high)
    {
        int mid = (low + high)/2;
        if((mid * mid) == n)
        {
            ans = mid;
            return ans;
        }
        else if((mid * mid) < n)
        {
            ans = mid;
            low = mid + 1;
        }
        else if((mid * mid) > n)
        {
            high = mid - 1;
        }
    }
        int num = 1;
    for(int i=1;i<=p;i++)
    {
        int k = 1;

         double temp = ans;
         double store = ans;
        while((ans * ans) <= n )
        {
         temp = store + (double)(k*(1/pow(10,num)));
         if((temp*temp)>n)
         {
            cout<<"hi"<<temp<<endl;
            break;
         }
         ans = temp;
         k++;
        }
        num++;
    }
    return ans;
}
int main(int argc, char const *argv[])
{
    int n , p;
    cin>>n>>p;
    cout<<"Answer :"<<findingRoots(n,p)<<endl;
    return 0;
}
