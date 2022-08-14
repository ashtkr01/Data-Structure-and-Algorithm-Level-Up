#include <bits/stdc++.h>
using namespace std;
// Helper function:
int countTriplets(vector<float> vctr, float r)
{
    unordered_map<float, int> left;
    unordered_map<float, int> right;
    int result = 0;
    // Filled the right map:
    for (auto x : vctr)
    {
        right[x]++;
    }
    // Iterate the vector:
    for (auto x : vctr)
    {
        int count = 1;
        if (right[x] == 1)
        {
            right.erase(x);
        }
        else
        {
            right[x]--;
        }
        if (left.find(x / r) != left.end())
        {
            count = count * (left[x / r]);
        }
        else
        {
            count = 0;
        }
        // search in right side:
        if (right.find(x*r) != right.end())
        {
            count = count * (right[x*r]);
        }
        else
        {
            count = 0;
        }
        left[x]++;
        result += count;
    }
    return result;
}

int main(int argc, char const *argv[])
{
    int n;
    float r;
    cin >> n >> r;
    // Create a vector:
    vector<float> vctr(n, 0);
    // Initialisation of vector:
    for (int i = 0; i < n; i++)
    {
        cin >> vctr[i];
    }
    // Call:
    cout << countTriplets(vctr, r) << endl;
    return 0;
}
