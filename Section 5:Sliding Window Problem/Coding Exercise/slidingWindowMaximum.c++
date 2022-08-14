#include <bits/stdc++.h>
using namespace std;

vector<int> maxInWindow(vector<int> input, int k)
{
    int j =0;
    int length = input.size();
    vector<int> vctr;
    deque<int> deq;
    // Insert first element :
    deq.push_front(input[0]);
    // Loop from 0 to k-1:
    for (int i = 1; i < k; i++)
    {
        if (input[i] < deq.back())
        {
            deq.push_back(input[i]);
        }
        else if (input[i] >= deq.back())
        {
            deq.pop_back();
            deq.push_back(input[i]);
        }
    }
    vctr.push_back(deq.front());
    for (int i = 1; i <= length - k; i++)
    {
        j = i + k -1;
        if (input[i-1] == deq.front())
        {
            deq.pop_front();
        }
        if (input[j] < deq.back())
        {
            deq.push_back(input[j]);
        }
        else if (input[j] >= deq.back())
        {
          
            while(deq.empty() != 1 and deq.back() <= input[j] )
            {
                deq.pop_back();
            }
            deq.push_back(input[j]);
            
        }
        vctr.push_back(deq.front());
    }
    return vctr;
}
//Main:
int main(int argc, char const *argv[])
{
    int n , k;
    cin>>n>>k;
    vector<int> vctr(n,0);
    vector<int> res;
    //Initialisation :
    for(int i=0;i<n;i++)
    {
        cin>>vctr[i];
    }
     res = maxInWindow(vctr , k);
     //Print :
     for(auto x : res)
     {
         cout<<x<<"   ";
     }
     cout<<endl;
    return 0;
}
