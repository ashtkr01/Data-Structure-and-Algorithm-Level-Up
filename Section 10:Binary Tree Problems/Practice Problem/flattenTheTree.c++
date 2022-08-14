#include<bits/stdc++.h>
using namespace std;
class nod{
    public:
    int data;
    nod* link;
    nod(int data){
      this->data = data;
      link =NULL;
    }
};
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
//Flatten
nod* flatten(node *root )
{
    nod *temp;
    if(root == NULL)
    {
        return NULL;
    }
    nod *temp2 = flatten(root->left);
    temp = new nod(root->data);
    temp2->link = temp;
    temp->link = flatten(root->right);
    return temp; 
}

//Main Function:
int main(int argc, char const *argv[])
{
   node *root = build();
// nod *temp = flatten(root);
// //Print the linked list:
// nod* temp2 = temp;
// while(temp2 != NULL)
// {
//     cout<<temp2->data<<"--";
// }
    return 0;
}
