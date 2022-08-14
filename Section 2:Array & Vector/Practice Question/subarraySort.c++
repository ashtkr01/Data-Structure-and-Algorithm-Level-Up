#include<bits/stdc++.h>
using namespace std;

	vector<int> printUnsorted(vector<int> arr, int n) {
	    // code here
        vector<int> vctr;
        vector<int> res;
        int minEle = INT_MAX;
        int min = -1;
        int max = -1;
        //Check for first element:
        if(arr[0] > arr[i])
        {
            vctr.push_back(0);
        }
        for(int i=1;i<n-1;i++)
        {
          if( arr[i-1] < arr[i] and  arr[i] > arr[i+1])
          {
            vctr.push_back(i);
          }
        }
        //Check
        if(vctr.size() == 1)
        {
            if(arr[vctr[0]] > arr[n-1])
            {
                res.push_back(vctr[0]);
                res.push_back(n-1);
                return res;
            }
        }
        for(auto x : vctr)
        {
            cout<<x<<" ";
        }
        cout<<endl;
        //
        int size = vctr.size();
        for(int i=vctr[0];i<n;i++)
        {
            if(minEle > arr[i])
            {
                minEle = arr[i];
            }
        }

        for(int i=0;i<n;i++)
        {
            if(minEle < arr[i])
            {
                min = i;
                break;
            }
        }

        
        for(int i=size-1;i<n;i++)
        {
            if(arr[vctr[size-1]] < arr[i])
            {
                max = i-1;
                break;
            }
        }
         
         res.push_back(min);
         res.push_back(max);

         return res;



	}

    int main(int argc, char const *argv[])
    {
        int n;
        cin>>n;
        vector<int> vctr(n , 0);
        vector<int> res;
        for(int i=0;i<n;i++)
        {
            cin>>vctr[i];
        }

        res = printUnsorted(vctr , n);
        //Print
        for(auto x : res)
        {
            cout<<x<<" ";
        }
        cout<<endl;
        return 0;
    }
    