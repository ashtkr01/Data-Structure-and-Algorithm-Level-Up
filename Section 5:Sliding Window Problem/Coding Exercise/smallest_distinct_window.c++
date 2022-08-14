#include<bits/stdc++.h>
using namespace std;

string smallestWindow(string str){
    //Complete this method
    int length = str.length();
    int i=0;
    int j=1;
    unordered_set<char> us;
    us.insert(str[i]);
    int curr_max =0;
    int max = INT_MIN;
    int res1 = -1;
    int res2=-1;
    while( j<length)
    {
        if(us.find(str[j]) != us.end())
        {
           curr_max = (j-i);
           if(curr_max > max)
           {
              res1 =i;
               res2 = j;
               max = curr_max;
           }
           while(us.find(str[j]) != us.end())
           {
               us.erase(str[i]);
               i++;
           }

        }
        else{
            us.insert(str[j]);
            j++;
        }
    }  
    curr_max = j-i;
       if(curr_max > max)
           {
              res1 =i;
               res2 = j;
               max = curr_max;
           }
        //    cout<<res1<<"----"<<res2<<endl;
          string result = str.substr(res1 , res2 - res1);
          return result;
}
//Main
int main(int argc, char const *argv[])
{
    string str;
    cin>>str;
    //Call:
    string res = smallestWindow(str);
    cout<<res<<endl;
    return 0;
}
