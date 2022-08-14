#include<bits/stdc++.h>
using namespace std;


class node{
public:
	int data;
	node* next;

	node(int data){
		this->data = data;
		next = NULL;
	}
};

int kthLastElement(node *head, int k){
    //Complete this function to return kth last element
    node *temp = head;
    node *temp2 = head;
    for(int i=1;i<k;i++)
    {
        temp2 = temp2->next;
    }
    while(temp2->next != NULL)
    {
        temp = temp->next;
        temp2 = temp2->next;
    }
    return temp->data;
}