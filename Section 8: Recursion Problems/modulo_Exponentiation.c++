#include<bits/stdc++.h>
using namespace std;
long long int maximum = 1000000007;
long long int powerModulo(int a, int b){
    //Write your code here. Do not modify the function or parameters. Use helper functions if needed.
    if(b == 0)
    {
        return 1;
    }
    long long int ans = 1;
    if(b % 2 == 0)
    {
        ans =( ( powerModulo(a , b/2))%maximum * (powerModulo(a,b/2))%maximum) % maximum;
    }
    else if(b % 2 != 0)
    {
        ans = ((a%maximum)*( ( powerModulo(a , b/2))%maximum * (powerModulo(a,b/2))%maximum)) % maximum;
    }
    return ans;
}
//Main:
int main(int argc, char const *argv[])
{
    int a , b;
    cin>>a>>b;
    cout<<powerModulo( a , b )<<endl;
    return 0;
}
