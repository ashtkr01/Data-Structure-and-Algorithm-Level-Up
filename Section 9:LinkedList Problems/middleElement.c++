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

int getMid(node *head){
    //Complete this function to return data middle node
    node *temp1 = head;
    node *temp2 = head;

    while( temp2->next != NULL and temp2->next->next != NULL)
    {
        temp1=temp1->next;
        temp2=temp2->next->next;
    }
    
    return temp1->data;
    
    
}