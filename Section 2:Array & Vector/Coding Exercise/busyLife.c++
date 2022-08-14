#include<bits/stdc++.h>
using namespace std;

//Camparator :
bool compare(pair<int , int > a , pair<int , int > b)
{
    if(a.second != b.second)
    {
    return a.second < b.second ;
    }
    else{
        a.first < b.first;
    }
}

int countActivites(vector<pair<int,int> > activities){
    //Complete this method
    int cnt =0;
    int previousEndTime =0;
    //Sort the activit based on the which activity has been done shortly:
    sort(activities.begin() , activities.end() , compare);
    
    //Iterate over all vector
    for(auto x : activities)
    {
        if(previousEndTime <= x.first)
        {
            cnt++;
            previousEndTime = x.second;
        }
    }
    return cnt;
}
//Main function:
int main(int argc, char const *argv[])
{
    vector<pair<int ,int>> vctr{{7,9} , {0 , 10} , {4 , 5} , {8 , 9} , { 4,10} , {5 , 7}};
    int res = 0;
    res = countActivites(vctr);
    cout<<"Answer :"<<res<<endl;
    return 0;
}
