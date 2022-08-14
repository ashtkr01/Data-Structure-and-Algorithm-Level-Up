#include<bits/stdc++.h>
using namespace std;

int rotatedSearch(vector<int> vctr , int key)
{
    int low = 0;
    int high = vctr.size() - 1;
    while(low <= high)
    {
        int mid = (low + high)/2;
        if(vctr[mid] == key)
        {
            return mid;
        }
        else if(vctr[low] <= vctr[mid])
        {
            if(vctr[low] <= key and key < vctr[mid])
            {
                high = mid - 1;
            }
            else{
                low = mid + 1;
            }
        }
        else if(vctr[mid] <= vctr[high])
        {
            if(key <= vctr[high] and key > vctr[mid])
            {
                low = mid + 1;
            }
            else{
                high = mid - 1;
            }
        }
    }
    return -1;
}
int main(int argc, char const *argv[])
{
    int n , key;
    cin>>n>>key;
    vector<int> vctr(n , 0);
    for(int i=0;i<n;i++)
    {
        cin>>vctr[i];
    }
    int ans = rotatedSearch(vctr , key);
    cout<<"Answer :"<<ans<<endl;
    return 0;
}
