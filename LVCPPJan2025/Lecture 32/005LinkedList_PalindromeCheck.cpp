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

ListNode* reverseIterative(ListNode* head) {

	ListNode* cur = head;
	ListNode* prev = NULL;

	while (cur != NULL) {
		ListNode* temp = cur->next;
		cur->next = prev;
		prev = cur;
		cur = temp;
	}

	return prev;
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

// 3n/2 steps
// time : O(n)
// space: O(1)

bool checkPalindrome(ListNode* head1) {

	// 1. divide the linkedList around the midPoint

	ListNode* midPoint = findMidPoint(head1); // n/2 steps
	ListNode* head2 = midPoint->next;
	midPoint->next = NULL;

	// 2. reverse the second sublist

	head2 = reverseIterative(head2); // n/2 steps

	// 3. compare the 1st sublist with the reversed 2nd sublist

	while (head2 != NULL) { // n/2 steps
		if (head1->val != head2->val) { // linkedList is not a palindrome
			return false;
		}
		head1 = head1->next;
		head2 = head2->next;
	}

	return true; // linkedList is a palindrome
}

int main() {

	ListNode* head = NULL;

	insertAtHead(head, 10);
	insertAtHead(head, 20);
	insertAtHead(head, 40);
	insertAtHead(head, 30);
	insertAtHead(head, 20);
	insertAtHead(head, 10);

	printLinkedList(head);

	checkPalindrome(head) ? cout << "palindrome" << endl : cout << "not a palindrome" << endl;

	return 0;
}