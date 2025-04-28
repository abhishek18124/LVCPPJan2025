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

void printLinkedList(ListNode* head) { // here head ptr must be passed by value since we don't want changes done to head ptr to be reflected in the caller fn

	while (head != NULL) {
		cout << head->val << " ";
		head = head->next;
	}

	cout << endl;

}

ListNode* getTail(ListNode* head) { // here head ptr must be passed by value since we don't want changes done to head ptr to be reflected in the caller fn
	while (head->next != NULL) {
		head = head->next;
	}
	return head;
}

// time : O(n) where n is the length of the linkedList

void insertAtTail(ListNode*& head, int val) {

	if (head == NULL) {
		// insertion at tail is equivalent to insertion at head
		insertAtHead(head, val);
		return;
	}

	ListNode* n = new ListNode(val); // const
	ListNode* tail = getTail(head); // linear
	tail->next = n; // const

}

int main() {

	ListNode* head = NULL; // initially, linkedList is empty

	// insertAtHead(head, 50);
	// insertAtHead(head, 40);
	// insertAtHead(head, 30);
	// insertAtHead(head, 20);
	// insertAtHead(head, 10);

	// printLinkedList(head); // 10 20 30 40 50

	insertAtTail(head, 60);

	printLinkedList(head); // 10 20 30 40 50 60

	return 0;
}
