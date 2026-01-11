// palindrome linked list

#include <bits/stdc++.h>
using namespace std;

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

struct ListNode {
   int val;
   ListNode *next;
   ListNode() : val(0), next(nullptr) {}
   ListNode(int x) : val(x), next(nullptr) {}
   ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    bool isPalindrome(ListNode* head) {
        if(head == NULL || head->next == NULL)
            return true; // it is palindrome if there is one node or no node
        ListNode *slow = head;
        ListNode *fast = head;
        while(fast!=NULL && fast->next!=NULL){
            slow = slow->next;
            fast = fast->next->next;
        }
        ListNode *preptr = NULL;
        ListNode *ptr = slow;
        ListNode *postptr;
        while(ptr){
            postptr = ptr->next;
            ptr->next = preptr;
            preptr = ptr;
            ptr = postptr;
        }

        ListNode *left = head;
        ListNode *right = preptr;
        while(right!=NULL){
            if(left->val != right->val)
                return false;
            left = left->next;
            right = right->next;
        }
        return true;
    }
};


/*
    TEST CASE 1: Even Length Palindrome
    Input: 1 -> 2 -> 2 -> 1
    Middle: Starts at second 2. Reversed: 1 -> 2.
    Compare: (1,1) and (2,2) -> Match!
    Result: true

    TEST CASE 2: Odd Length Palindrome
    Input: 1 -> 2 -> 3 -> 2 -> 1
    Middle: Starts at 3. Reversed: 1 -> 2 -> 3.
    Compare: (1,1) and (2,2) -> Match!
    Result: true

    TEST CASE 3: Not a Palindrome
    Input: 1 -> 2 -> 3
    Middle: Starts at 2. Reversed: 3 -> 2.
    Compare: (1,3) -> Fail!
    Result: false
*/