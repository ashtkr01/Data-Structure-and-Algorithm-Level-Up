#include<bits/stdc++.h>
using namespace std;
string breakPalindrome(string palindrome) {
    int length = palindrome.length();
    int skipIdx = -1;
    int cnt = 0;
    if(length == 1)
    {
       return "";
    }    
    if(length %2 !=0)
    {
        skipIdx = length/2;
    }
    //Iterate over all character
    for(int i=0;i<length;i++)
    {
        if(palindrome[i] != 'a' and i!= skipIdx)
        {
            palindrome[i] = 'a';
            cnt = 1;
        }
        if(cnt == 1)
        {
            break;
        }
    }
    //Check:
    if(cnt != 1)
    {
        for(int i=length-1;i>=0;i--)
        {
            if(palindrome[i] >= 'a' and palindrome[i] <'z' and i != skipIdx)
            {
                // cout<<"hi"<<endl;
                char ch = palindrome[i];
                ch++;
                palindrome[i] = ch;
                cnt=1;
            }
            if(cnt == 1)
            {
                break;
            }
        }
    }
    return palindrome;
}
//Main
int main(int argc, char const *argv[])
{
    string str = "";
    cin>>str;
    string res ="";
    res = breakPalindrome(str);
    cout<<res<<endl;
    return 0;
}
