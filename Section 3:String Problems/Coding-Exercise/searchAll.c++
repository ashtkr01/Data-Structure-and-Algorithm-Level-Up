#include <bits/stdc++.h>
using namespace std;

vector<int> stringSearch(string big, string small)
{
    // store the occurrences in the result vector
    vector<int> result = {};
    // cout<<big<<endl;
    // cout<<small<<endl;
    int length = big.size();
    int len = small.size();

    for (int i = 0; i < length; i++)
    {
        if (big[i] == small[0])
        {
            int j = 1;
            int idx = i + 1;
            while (j < len and idx < length)
            {
                if (small[j] == big[idx] and j != len - 1)
                {
                    j++;
                    idx++;
                }
                else if (small[j] == big[idx] and j == len - 1)
                {
                    // cout<<i<<endl;
                    result.push_back(i);
                    j++;
                    idx++;
                }
                else
                {
                    break;
                }
            }
        }
    }
    return result;
}
//Main Function:
int main(int argc, char const *argv[])
{
    string bigString = "I liked the movie , acting in movie was great";
    string smallString = "movie";
    vector<int> vctr;
    //Call:
    vctr = stringSearch(bigString , smallString);
    //Print:
    for(int i=0;i<vctr.size();i++)
    {
        cout<<vctr[i]<<" ";
    }
    cout<<endl;
    return 0;
}

