#include<bits/stdc++.h>
using namespace std;

//Complete this method, don't write main
vector<string> fizzbuzz(int n){
   vector<string> vctr;

   for(int i=1;i<=n;i++)
   {
       if(i%3==0 and i%5==0)
       {
           vctr.push_back("FizzBuzz");
       }
       else if(i%3==0)
       {
           vctr.push_back("fizz");
       }
       else if(i%5==0)
       {
           vctr.push_back("Buzz");
       }
       else{
           vctr.push_back(to_string(i));
       }
   }
   return vctr;   
}

//Main 
int main(int argc, char const *argv[])
{
    int n;
    cin>>n;
    vector<string> vctr;
    vctr = fizzbuzz(n);
    return 0;
}
