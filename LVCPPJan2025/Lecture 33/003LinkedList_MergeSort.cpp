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

ListNode* mergeSortedLinkedList(ListNode* head1, ListNode* head2) {

	ListNode* dummy = new ListNode(0);
	ListNode* temp = dummy;

	while (head1 != NULL and head2 != NULL) {
		if (head1->val < head2->val) {
			temp->next = head1;
			temp = temp->next;
			head1 = head1->next;
		} else {
			temp->next = head2;
			temp = temp->next;
			head2 = head2->next;
		}
	}

	if (head1 != NULL) {
		temp->next = head1;
	}

	if (head2 != NULL) {
		temp->next = head2;
	}

	return dummy->next;

}

ListNode* findMidPoint(ListNode* head) {

	if (head == NULL) {
		// linkedList is empty
		return head;
	}

	ListNode* slow = head;
	ListNode* fast = head->next;

	while (fast != NULL and fast->next != NULL) {
		slow = slow->next;
		fast = fast->next->next;
	}

	return slow;

}

// time : O(nlogn)
// space: O(logn) due to fn call stack

ListNode* mergeSort(ListNode* head1) {

	// base case

	// if(head1 == NULL) {
	// 	// linkedList is empty
	// 	return head1;
	// }

	// if(head1->next == NULL) {
	// 	// size of the linkedList is one
	// 	return head1;
	// }

	if (head1 == NULL || head1->next == NULL) {
		return head1;
	}

	// recursive case

	// linkedList has >= 2 nodes

	ListNode* midPoint = findMidPoint(head1);
	ListNode* head2 = midPoint->next;
	midPoint->next = NULL;

	head1 = mergeSort(head1);
	head2 = mergeSort(head2);

	return mergeSortedLinkedList(head1, head2);

}


int main() {

	ListNode* head = NULL;

	insertAtHead(head, 10);
	insertAtHead(head, 20);
	insertAtHead(head, 30);
	insertAtHead(head, 40);
	insertAtHead(head, 50);

	printLinkedList(head);

	head = mergeSort(head);

	printLinkedList(head);

	return 0;
}