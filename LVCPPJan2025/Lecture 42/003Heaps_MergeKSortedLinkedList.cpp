/*

    Given k sorted linked list, merge them and print the sorted output.

    k = 3
    Input : 0->3->6
            1->4->7
            2->5->8

    Output: 0->1->2->3->4->5->6->7->8

*/

#include<iostream>
#include<queue>
#include<vector>

using namespace std;

class ListNode {

public :

    int val;
    ListNode* next;

    ListNode() {
        this->val = 0;
        this->next = NULL;
    }

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

class ListNodeCmp {
public:

    // return false if you want a to be given more priority than b otherwise return true

    bool operator()(ListNode* a, ListNode* b) {
        if (a->val < b->val) {
            // we want to give a higher priority than b since we are building
            // minHeap based on node values
            return false;
        }
        return true;
    }
};

class Solution {
public:

    // time : O(nklogk)
    // space: O(k) due to minHeap

    ListNode* mergeKLists(vector<ListNode*>& v) {

        ListNode* dummy = new ListNode();
        ListNode* temp = dummy;

        priority_queue<ListNode*, vector<ListNode*>, ListNodeCmp> minHeap(v.begin(), v.end());

        while (!minHeap.empty()) {
            ListNode* minNode = minHeap.top();
            minHeap.pop();
            temp->next = minNode;
            temp = temp->next;
            if (minNode->next != NULL) {
                minHeap.push(minNode->next);
            }
        }

        return dummy->next;

    }
};

int main() {

    ListNode* head1 = NULL;

    insertAtHead(head1, 6);
    insertAtHead(head1, 3);
    insertAtHead(head1, 0);

    printLinkedList(head1);

    ListNode* head2 = NULL;

    insertAtHead(head2, 7);
    insertAtHead(head2, 4);
    insertAtHead(head2, 1);

    printLinkedList(head2);

    ListNode* head3 = NULL;

    insertAtHead(head3, 8);
    insertAtHead(head3, 5);
    insertAtHead(head3, 2);

    printLinkedList(head3);

    vector<ListNode*> v = {head1, head2, head3};

    Solution s;
    ListNode* head = s.mergeKLists(v);

    printLinkedList(head);

    return 0;
}
