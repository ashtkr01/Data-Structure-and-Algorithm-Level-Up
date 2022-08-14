#include<bits/stdc++.h>
using namespace std;

//Expected Complexity O(N)
vector<int> productArray(vector<int> arr){
    
    //Create an output Array
    int n = arr.size();
    vector<int> output(n,1);
    
    //update the output array and return
    //complete the code
    vector<int> vctr1;
    vector<int> vctr2;
    //Copy the vector:
    vctr1= arr;
    vctr2=arr;
    //build left vector:
    for(int i=1;i<n;i++)
    {
        vctr1[i] = vctr1[i]*vctr1[i-1];
    }
    // Build Right vector
    for(int j=n-2;j>=0;j--)
    {
        vctr2[j] = vctr2[j] *vctr2[j+1];
    }
    //Build our own vector
    for(int i=0;i<n;i++)
    {
        if(i==0 and n>2)
        {
            output[i] = vctr2[i+1];
        }
        else if(i==0 or (i==n-1 and n-1 == 0))
        {
            output[i] = arr[0];
        }
        else if(i==n-1)
        {
            output[i] = vctr1[i-1];
        }
        else{
            output[i] = vctr1[i-1]*vctr2[i+1];
        }
        
    }
    
    return output;
}
//Main function:
int main(int argc, char const *argv[])
{
    int n;
    cin>>n;
    vector<int> vctr(n,0);
    vector<int> res(n,0);
    //Initialisation:
    for(int i=0;i<n;i++)
    {
        cin>>vctr[i];
    }
    //Call:
    res = productArray(vctr);
    //Print:
    for(auto x : res)
    {
        cout<<x<<" ";
    }
    cout<<endl;
    return 0;
}
