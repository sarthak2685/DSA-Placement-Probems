// https://leetcode.com/problems/swap-nodes-in-pairs/description/

// Swap Nodes in Pairs

// Given a linked list, swap every two adjacent nodes and return its head. 
// You must solve the problem without modifying the values in the list's nodes 
// (i.e., only nodes themselves may be changed.)

// Example 1:
// Input: head = [1,2,3,4]
// Output: [2,1,4,3]

// Example 2:
// Input: head = []
// Output: []

// Example 3:
// Input: head = [1]
// Output: [1]
 
// Constraints:

// The number of nodes in the list is in the range [0, 100].
// 0 <= Node.val <= 100

#include <iostream>
using namespace std;

// Definition for singly-linked list
struct ListNode {
    int val;
    ListNode* next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode* next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        if (head == NULL || head->next == NULL)
            return head;
  
        ListNode* prev = head;
        ListNode* curr = head->next;
  
        head = curr;
        while (true) {
            ListNode* next = curr->next;
            curr->next = prev; 
            if (next == NULL || next->next == NULL) {
                prev->next = next;
                break;
            }
  
            prev->next = next->next;
            prev = next;
            curr = prev->next;
        }
        return head;
    }
};

int main() {
    ListNode* head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(4);

    cout << "Original Linked List: ";
    ListNode* temp = head;
    while (temp != NULL) {
        cout << temp->val << " -> ";
        temp = temp->next;
    }
    cout << "NULL" << endl;

    Solution solution;
    ListNode* swappedHead = solution.swapPairs(head);

    cout << "Modified Linked List: ";
    temp = swappedHead;
    while (temp != NULL) {
        cout << temp->val << " -> ";
        temp = temp->next;
    }
    cout << "NULL" << endl;

    return 0;
}
