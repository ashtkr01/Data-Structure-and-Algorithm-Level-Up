#include<bits/stdc++.h>
using namespace std;

int earthLevel(int k)
{
    int n = k;
    int res = 0;
    int a = 2;
    //your code goes here
    while(n > 0)
    {
        a = pow(a , 0);
        int power = 0;
        while(a <= n)
        {
           power++;
           a = pow(2,power);
        }
        if(power != 0)
        {
            a = pow(2,power-1);
        }
        n = n - a;
        res++;
    }
    return res;
    
}