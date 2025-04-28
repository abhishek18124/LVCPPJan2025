#include<iostream>

using namespace std;

class ListNode {

public:

	int val;
	ListNode* next;

	ListNode(int val) {
		this->val = val;
		this->next = NULL;
	}

};

// time : O(1)

void insertAtHead(ListNode*& headRef, int val) { // here we are passing head ptr by ref since we want changes done to head inside the fn to be reflected in the caller

	ListNode* n = new ListNode(val);
	n->next = headRef;
	headRef = n;

}

void printLinkedList(ListNode* head) { // here we are passing head ptr by value since we don't want changes done to the head to be reflected in the caller fn

	while (head != NULL) {
		cout << head->val << " ";
		head = head->next;
	}

	cout << endl;

}

int main() {

	ListNode* head = NULL; // initially, linkedList is empty

	insertAtHead(head, 50);
	insertAtHead(head, 40);
	insertAtHead(head, 30);
	insertAtHead(head, 20);
	insertAtHead(head, 10);

	// if (head == NULL) {
	// 	cout << "Linked List is empty" << endl;
	// }

	printLinkedList(head); // 10 20 30 40 50

	printLinkedList(head); // 10 20 30 40 50

	insertAtHead(head, 0);

	printLinkedList(head); // 0 10 20 30 40 50

	return 0;

}