// Remove Nth node from end of the List
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */

#include <bits/stdc++.h>
using namespace std;
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode *dummy = new ListNode(0);
        dummy->next = head;
        ListNode *slow = dummy;
        ListNode *fast = dummy;
        for(int i = 0; i<n; i++)
            fast = fast->next;
        while(fast->next!=NULL){
            slow = slow->next;
            fast = fast->next;
        }
        slow->next = slow->next->next;
        return dummy->next;
    }
};

/*
    TEST CASE 1: Standard Middle Removal
    Input: head = [1, 2, 3, 4, 5], n = 2
    --------------------------------------
    - Gap: 'fast' moves 2 steps to Node 2.
    - Move: both move until 'fast' is at Node 5. 'slow' lands on Node 3.
    - Action: 3->next becomes 5 (skips 4).
    Expected Output: [1, 2, 3, 5]

    TEST CASE 2: Removing the Head (Corner Case)
    Input: head = [1, 2, 3], n = 3
    --------------------------------------
    - Gap: 'fast' moves 3 steps to Node 3.
    - Move: 'fast->next' is already NULL, so 'slow' stays at Dummy.
    - Action: Dummy->next becomes Node 2 (skips Node 1).
    Expected Output: [2, 3]

    TEST CASE 3: Single Node List (Edge Case)
    Input: head = [1], n = 1
    --------------------------------------
    - Gap: 'fast' moves 1 step to Node 1.
    - Move: 'fast->next' is NULL.
    - Action: Dummy->next becomes NULL.
    Expected Output: []

    TEST CASE 4: Removing the Last Node
    Input: head = [1, 2], n = 1
    --------------------------------------
    - Gap: 'fast' moves 1 step to Node 1.
    - Move: both move 1 step. 'fast' is at 2, 'slow' is at 1.
    - Action: 1->next becomes NULL (skips 2).
    Expected Output: [1]
*/