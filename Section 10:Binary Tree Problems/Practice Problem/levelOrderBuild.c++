#include<bits/stdc++.h>
using namespace std;

class node{
    public :
          int d;
          node *left;
          node *right;
    node(int d)
    {
        this->d = d;
        left = NULL;
        right = NULL;
    }      
};
//Traversal :
void traversal(node * root)
{
    if(root == NULL)
    {
        return;
    }
    cout<<root->d<<" ";
      traversal(root->left);
      traversal(root->right);
}

int main(int argc, char const *argv[])
{
    queue<node *> qu;
    int d;
    cin>>d;
    node *root = new node(d);
    qu.push(root);
    // if(d != -1)
    // {
    //     temp =  new node(d);
    //     qu.push(temp);
    // }
    while(qu.empty() != 1)
    {
          int d;
        cout<<"HI"<<endl;
        node *temp = qu.front();
        qu.pop();
        cin>>d;
        if(d != -1)
        {
            temp->left = new node(d);
            qu.push(temp->left);
        }
        cin>>d;
        if(d != -1)
        {
            temp->right = new node(d);
            qu.push(temp->right);
        }
    }
    cout<<root->d<<endl;
    // TRaversal
    traversal(root);
    /* code */
    return 0;
}
