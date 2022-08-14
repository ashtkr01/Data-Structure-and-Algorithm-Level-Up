#include <bits/stdc++.h>
using namespace std;
/****************************First Approach********************************/
int longest_band(vector<int> vctr, int n)
{
    unordered_set<int> us;
    for (auto x : vctr)
    {
        us.insert(x);
    }
    int ans = 0;
    int max = 0;
    for (auto x : us)
    {
        int a = x;
        int b = x + 1;
        int cnt = 0;

        while (us.find(a) != us.end())
        {
            cnt++;
            us.erase(a);
            a--;
        }
        while (us.find(b) != us.end())
        {
            cnt++;
            us.erase(b);
            b++;
        }
        if (cnt > ans)
        {
            ans = cnt;
        }
    }
    return ans;
}
int main(int argc, char const *argv[])
{
    int n;
    cin >> n;
    vector<int> vctr(n, 0);
    for (int i = 0; i < n; i++)
    {
        cin >> vctr[i];
    }
    cout<<"Answer : "<<longest_band(vctr , n)<<endl;
    return 0;
}
