#include<bits/stdc++.h>
using namespace std;

string convert_to_digital_time(int minutes){
    //complete this function
    int a=minutes/60;
    int b=minutes%60;
    
    string str=to_string(a);
    str+=":";
    if(b/10==0)
    {
       str+="0"+to_string(b); 
    }
    else
    str+=to_string(b);
    return str;
    
}
//Main
int main(int argc, char const *argv[])
{
    int n;
    cin>>n;
    string str="";
    str = convert_to_digital_time(n);
    cout<<"Result : "<<str<<endl;
    return 0;
}
