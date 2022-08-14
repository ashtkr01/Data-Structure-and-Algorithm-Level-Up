#include <bits/stdc++.h>
using namespace std;

int badness(vector<pair<string, int>> teams)
{
    // Complete this function to return the min badness
    int length = teams.size();
    int pos = 1;
    int sum = 0;
    vector<int> count(length + 1, 0);
    // Iterate the whole vector:
    for (int i = 0; i < length; i++)
    {
        count[teams[i].second]++;
    }

    // Iterate count vector:
    for (int i = 0; i < length; i++)
    {
        while (count[i])
        {
            sum += abs(pos - (i + 1));
            count[i]--;
            pos++;
        }
    }
    return sum;
}