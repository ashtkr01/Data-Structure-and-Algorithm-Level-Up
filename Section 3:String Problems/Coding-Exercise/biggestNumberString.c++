#include<bits/stdc++.h>
using namespace std;
//Function to find number of digit
int numOfDigit(int max)
{
   //Count the umber of digit:
    int digit =0;
    while(max > 0)
    {
        digit++;
        max = max/10;
    }
    return digit;
}
//Comaparator
bool compare(pair<int , int> a , pair<int , int> b)
{
    return a.first > b.first;
}
//Function:
string concatenate(vector<int> numbers){
    //complete this method and return the largest number you can form as a string
    vector<pair<int , int >> vctr;
    string str ="";
    int max=INT_MIN;
    int length = numbers.size();
    for(int i=0;i<length;i++)
    {
        if(numbers[i] > max)
        {
            max = numbers[i];
        }
    }
    int maxDigit = numOfDigit(max);

    for(int i=0;i<length;i++)
    {
        int digit = numOfDigit(numbers[i]);
        if(maxDigit > digit)
        {
            int num = numbers[i];
            int last = (numbers[i])%10;
            for(int x=digit;x<maxDigit;x++)
            {
               num = num*10 + last;
            }
             vctr.push_back({num , i});
        }
        else{
            vctr.push_back({numbers[i] , i});
        }
    }

    //Sort 
    sort(vctr.begin() , vctr.end() , compare);

    // //print:
    // for(int i=0;i<vctr.size();i++)
    // {
    //     cout<<vctr[i].first<<" "<<vctr[i].second<<endl;
    // }
    for(auto x : vctr)
    {
        str += to_string(numbers[x.second]);
    }
    // cout<<"Answer : "<<str<<endl;
    return str;
}
//Main:
int main(int argc, char const *argv[])
{
    vector<int> vctr{10,11,20,30,3};
    //Call:
    concatenate(vctr);
    return 0;
}
