#include<bits/stdc++.h>
using namespace std;
class node{
    public :
          int data;
          node *left;
          node *right;
          node(int data)
          {
              this->data = data;
              left = NULL;
              right = NULL;
          }
};
// Comparator :
bool compare(pair<int , int> a, pair<int,int> b)
{
    if(a.second != b.second)
    {
        return a.second < b.second;
    }
    else{
        return a.first < b.first;
    }
}
//Build
node * build()
{
    int d ;
    cin>>d;
    if(d==-1)
    {
        return NULL;
    }
    node *temp = new node(d);
    temp->left = build();
    temp->right = build();

    return temp;
}
//Print Vertical Order:
void printVerticalOrder(node * root ,int val , vector<pair<int,int>> &vctr)
{
    if(root == NULL)
    {
        return;
    }
    pair<int , int> p = {root->data , val};
    vctr.push_back(p);
    printVerticalOrder(root->left , val-1 , vctr);
    printVerticalOrder(root->right , val+1 , vctr);
}
//Main Function:
int main(int argc, char const *argv[])
{
   node *root = build();
   vector<pair<int,int>> vctr;
//    Call
    printVerticalOrder(root , 0, vctr);
    sort(vctr.begin() , vctr.end() , compare);
    for(auto x : vctr)
    {
        cout<<x.first<<"  "<<endl;
    }
    return 0;
}
