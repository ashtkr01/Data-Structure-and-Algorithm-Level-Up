#include<bits/stdc++.h>
using namespace std;

//str is the input the string
string compressString(const string &str){   
    //complete the function to return output string
    string str1 ="";
    int length = str.length();
     int count=1;
     for(int i=0;i<length;)
     {
        char d = str[i];
        i++;
        count =1;
        while(str[i] == d)
        {
            count++;
            i++;
        }
        str1 += d;
        str1 += to_string(count);
     }
    if(str1.length() > length)
    {
        return str;
    }
    else{
        return str1;
    } 
}
//Main:
int main(int argc, char const *argv[])
{
    string result ="";
    string str = ""; 

    cin>>str;
    result = compressString(str);
    cout<<result<<endl;
    return 0;
}
