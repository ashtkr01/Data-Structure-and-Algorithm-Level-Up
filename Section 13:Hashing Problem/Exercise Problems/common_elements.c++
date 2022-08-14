#include<bits/stdc++.h>
using namespace std;

vector<int> commonElements(vector<int> v1, vector<int> v2){
    //Write your code here. Do not modify the function or the parameters. You can use helper function if needed.
    unordered_set<int> st;
    vector<int> vctr;
    //Iterate first vector:
    for(auto x : v1)
    {
        st.insert(x);
    }
    //Iterate the second vector:
    for(auto x : v2)
    {
        if(st.find(x) != st.end())
        {
            vctr.push_back(x);
        }
    }
    sort(vctr.begin() , vctr.end());
    return vctr;
}