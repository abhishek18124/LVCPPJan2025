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

	while (head != NULL) {
		cout << head->val << " ";
		head = head->next;
	}

	cout << endl;
}

void deleteAtHead(ListNode*& head) {

	if (!head) { // head == NULL
		// linkedList is empty
		return;
	}

	ListNode* temp = head;
	head = head->next;
	delete temp;
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

void deleteAtIndex(ListNode*& head, int i) {

	if (i == 0) {
		// deletion at index 0 is equivalent to deletion at head
		deleteAtHead(head);
		return;
	}

	ListNode* prev = getNode(head, i - 1);
	if (prev == NULL) {
		// index i is not valid
		return;
	}

	// cout << "prev exists" << endl;

	ListNode* cur = prev->next;
	if (cur == NULL) {
		// index i is not valid
		return;
	}

	// cout << "cur exists" << endl;

	prev->next = cur->next;
	delete cur;

}

int main() {

	ListNode* head = NULL; // initially, linkedList is empty

	insertAtHead(head, 50);
	insertAtHead(head, 40);
	insertAtHead(head, 30);
	insertAtHead(head, 20);
	insertAtHead(head, 10);

	printLinkedList(head);

	deleteAtIndex(head, 3);

	printLinkedList(head);

	return 0;
}