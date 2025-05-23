#include<iostream>

using namespace std;

class ListNode {

public :

	int val;
	ListNode* next;

	ListNode(int val) {
		this->val = val;
		this->next = NULL;
	}

};

void insertAtHead(ListNode*& head, int val) {

	ListNode* n = new ListNode(val);
	n->next = head;
	head = n;

}

void printLinkedList(ListNode* head) {

	while (head) { // head != NULL
		cout << head->val << " ";
		head = head->next;
	}

	cout << endl;

}

ListNode* getNode(ListNode* head, int j) {

	// find the node at index j in the linkedList and return its addr

	int k = 1;

	while (head != NULL and k <= j) { // head != NULL condn is added to make sure we don't deref NULL ptr which can happen in case j is invalid (exceeds range of valid indices)
		head = head->next;
		k++;
	}

	return head;

}

// time : O(n)

void insertAtIndex(ListNode*& head, int i, int val) {

	if (i == 0) {
		// insertion at index 0 is equivalent to insertion at head
		insertAtHead(head, val);
		return;
	}

	ListNode* n = new ListNode(val); // const
	ListNode* prev = getNode(head, i - 1); // linear
	if (prev == NULL) {
		// index i is invalid
		return;
	}
	n->next = prev->next; // const
	prev->next = n; // const

}

int main() {

	ListNode* head = NULL; // initially, linkedList is empty

	insertAtHead(head, 50);
	insertAtHead(head, 40);
	insertAtHead(head, 30);
	insertAtHead(head, 20);
	insertAtHead(head, 10);

	printLinkedList(head);

	insertAtIndex(head, 2, 25);

	printLinkedList(head);

	insertAtIndex(head, 0, 5);

	printLinkedList(head);

	return 0;
}