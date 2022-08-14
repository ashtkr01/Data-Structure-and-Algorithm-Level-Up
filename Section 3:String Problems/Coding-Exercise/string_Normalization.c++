#include<bits/stdc++.h>
using namespace std;

string normalize(const string &sentence) {
    string copy = sentence;
    //Make the changes in copy, and return it
    int length = copy.length();
    //Iterate:
    copy[0] = toupper(copy[0]);
    for(int i=1;i<length;i++)
    {
        if(copy[i-1] == ' ')
        {
            copy[i] = toupper(copy[i]);
        }
        else{
            copy[i] = tolower(copy[i]);
        }
    }
    return copy;
}
//Main:
int main(int argc, char const *argv[])
{
    string str = "this is SO MUCH FUN!";
    cout<<normalize(str)<<endl;
    return 0;
}
