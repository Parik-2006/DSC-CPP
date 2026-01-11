// Linked List Cycle

#include <bits/stdc++.h>
using namespace std;

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */


struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    bool hasCycle(ListNode *head) {
        if(head == NULL || head->next == NULL)
            return false;
        ListNode *slow = head;
        ListNode *fast = head;
        while(fast!=NULL && fast->next!=NULL){
            slow = slow->next;
            fast = fast->next->next;

            if(slow == fast)
            return true;
        }
        return false;
    }
};

int main(){

}

/*
    TEST CASE 1: Circular Loop
    Input: head = [3, 2, 0, -4], pos = 1 (Node -4 points back to Node 2)
    Expected: true (Fast will catch Slow at Node -4 or 0)

    TEST CASE 2: No Loop
    Input: head = [1, 2, 3], pos = -1 (Last node points to NULL)
    Expected: false

    TEST CASE 3: Tiny Loop
    Input: head = [1, 2], pos = 0 (Node 2 points back to Node 1)
    Expected: true
*/