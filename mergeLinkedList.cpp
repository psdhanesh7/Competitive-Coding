// Given two linked lists sorted in increasing order. Merge them such a way that the result list is in decreasing order (reverse order).
// Try solving without reverse, with O(1) auxiliary space (in-place) and only one traversal of both lists. You just need to return the head of new linked list, don't print the elements.

#include<iostream>
using namespace std;



 template <typename T>
 class Node {
	public:
	T data;
	Node* next;
 
	Node(T data) {
 next = NULL;
 this->data = data;
	}
 
	~Node() {
 if (next != NULL) {
 delete next;
 }
	}
 };
 
 
 


Node<int>* merge_reverse(Node<int>* head1,Node<int>* head2) {
	// Write your code here
    
    Node<int> *temp, *p, *q, *mergedListHead;
    
    mergedListHead = NULL;
    p = head1;
    q = head2;
    
    while(p != NULL && q != NULL)
    {
		if(p->data < q->data)
        {
			temp = p;
            p = p->next;
            temp->next = mergedListHead;
            mergedListHead = temp;
        }
        else
        {
            temp = q;
            q = q->next;
            temp->next = mergedListHead;
            mergedListHead = temp;
        }
        
    }
    while(p != NULL)
    {
        temp = p;
        p = p->next;
        temp->next = mergedListHead;
        mergedListHead = temp;
    }
    
    while(q != NULL)
    {
		temp = q;
        q = q->next;
        temp->next = mergedListHead;
        mergedListHead = temp;
    }
    
    return mergedListHead;
}

int main()
{
	return 0;
}
