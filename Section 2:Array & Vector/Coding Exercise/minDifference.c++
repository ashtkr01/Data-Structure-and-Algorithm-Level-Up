#include<bits/stdc++.h>
using namespace std;

// Function:
int findClosest(int element, vector<int> b)
{
    int start = 0;
    int end = b.size();
    int lastIdx = -1;
    while (start <= end)
    {
        int mid = (start + end) / 2;
        if (b[mid] == element)
        {
            return mid;
        }
        if (b[mid] > element)
        {
            end = mid - 1;
        }
        if (b[mid] < element)
        {
            lastIdx = mid;
            start = mid + 1;
        }
    }

    if (abs(b[lastIdx] - element) < abs(b[lastIdx + 1] - element))
    {
        return lastIdx;
    }
    else
    {
        return lastIdx + 1;
    }
}

pair<int, int> minDifference(vector<int> a, vector<int> b)
{
    // Complete this method
    pair<int, int> pr;
    // Sort the first vector:
    sort(a.begin(), a.end());
    // Sort the second vector:
    sort(b.begin(), b.end());
    // Function:
    int index = -1;
    int minDifferences = INT_MAX;

    for (int i = 0; i < a.size(); i++)
    {
        int element = a[i];

        int index = findClosest(element, b);

            if(abs(b[index] - element) < minDifferences)
        {
            minDifferences = abs(b[index] - element);
            pr.first = element;
            pr.second = b[index];
        }
    }
    return pr;
}

//Main function:
int main(int argc, char const *argv[])
{
     int n;
     cin>>n;
     //INitailization of first vector:
     vector<int> vctr1(n,0);
     vector<int> vctr2(n,0);
     pair<int , int > pr;
     for(int i=0;i<n;i++)
     {
         cin>>vctr1[i];
     }
     //Initailization of second vector:
     for(int i=0;i<n;i++)
     {
         cin>>vctr2[i];
     }
     //Call
     pr = minDifference(vctr1 , vctr2);
     cout<<"Answer : "<<pr.first<<" "<<pr.second<<endl;
    return 0;
}
