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
	while (head != NULL) {
		cout << head->val << " ";
		head = head->next;
	}
	cout << endl;
}

// ListNode* sumOfLinkedList(ListNode* head1, ListNode* head2) {

// 	ListNode* head = NULL;
// 	int carry = 0;

// 	while (head1 != NULL and head2 != NULL) {

// 		int sum = head1->val + head2->val + carry;

// 		ListNode* n = new ListNode(sum % 10);
// 		n->next = head;
// 		head = n;

// 		carry = sum / 10;

// 		head1 = head1->next;
// 		head2 = head2->next;

// 	}

// 	while (head1 != NULL) {

// 		int sum = head1->val + carry;

// 		ListNode* n = new ListNode(sum % 10);
// 		n->next = head;
// 		head = n;

// 		carry = sum / 10;

// 		head1 = head1->next;

// 	}

// 	while (head2 != NULL) {

// 		int sum = head2->val + carry;

// 		ListNode* n = new ListNode(sum % 10);
// 		n->next = head;
// 		head = n;

// 		carry = sum / 10;

// 		head2 = head2->next;

// 	}

// 	if (carry == 1) {
// 		ListNode* n = new ListNode(1);
// 		n->next = head;
// 		head = n;
// 	}

// 	return head;

// }

ListNode* sumOfLinkedList(ListNode* head1, ListNode* head2) {

	ListNode* head = NULL;
	int carry = 0;

	while (head1 != NULL or head2 != NULL or carry == 1) {

		int d1 = head1 != NULL ? head1->val : 0;
		int d2 = head2 != NULL ? head2->val : 0;
		int sum = d1 + d2 + carry;

		ListNode* n = new ListNode(sum % 10);
		n->next = head;
		head = n;

		carry = sum / 10;

		head1 = head1 != NULL ? head1->next : head1;
		head2 = head2 != NULL ? head2->next : head2;

	}

	return head;

}

int main() {

	ListNode* head1 = NULL;

	insertAtHead(head1, 1);
	insertAtHead(head1, 2);
	insertAtHead(head1, 3);
	insertAtHead(head1, 9);
	insertAtHead(head1, 8);
	insertAtHead(head1, 7);
	insertAtHead(head1, 6);

	printLinkedList(head1);

	ListNode* head2 = NULL;

	insertAtHead(head2, 9);
	insertAtHead(head2, 9);
	insertAtHead(head2, 9);
	insertAtHead(head2, 9);
	insertAtHead(head2, 9);

	printLinkedList(head2);

	ListNode* head = sumOfLinkedList(head1, head2);

	printLinkedList(head);

	return 0;
}