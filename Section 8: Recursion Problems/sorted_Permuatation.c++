#include<bits/stdc++.h>
using namespace std;

//Helper Function:
void helperFun(string s , int i , int j , unordered_set<string> &st , string osf)
{
    if(i>j)
    {
        st.insert(osf);
        return;
    }
    //loop
    for(int k=i;k<=j;k++)
    {
        swap(s[i] , s[k]);
        helperFun(s , i+1,j,st, osf + s[i]);
        swap(s[i] , s[k]);
    }
}

vector<string> findSortedPermutations(string s){
    //Your code goes here. Do not change the function or parameters. You can use helper functions if needed.
    vector<string> vctr;
    unordered_set<string> st;
    string osf= "";
    int i=0;
    int j = s.length()-1;
     //call
     helperFun(s , i , j , st , osf);
     //Print:
     for(auto x : st)
     {
         vctr.push_back(x);
     }
     
     sort(vctr.begin() , vctr.end());
     //Print final vector:
    //  for(auto x : vctr)
    //  {
    //      cout<<x<<"  ";
    //  }
     return vctr;
}
//Main;
int main(int argc, char const *argv[])
{
    string str = "";
    cin>>str;
    vector<string> res;
    res = findSortedPermutations(str);
    return 0;
}
