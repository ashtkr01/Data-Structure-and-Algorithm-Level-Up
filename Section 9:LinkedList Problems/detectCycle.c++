#include <bits/stdc++.h>
using namespace std;

class node
{
public:
    int data;
    node *next;

    node(int data)
    {
        this->data = data;
        next = NULL;
    }
};

bool containsCycle(node *head)
{
    // Complete this function
    unordered_set<node *> us;
    node *temp = head;

    while (temp != NULL)
    {
        if (us.find(temp) != us.end())
        {
            return true;
        }
        us.insert(temp);
        temp = temp->next;
    }
    return false;
}