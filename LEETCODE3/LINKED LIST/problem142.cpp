// Linked List Cycle 2

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

#include <bits/stdc++.h>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        if(head == NULL || head->next == NULL)
            return nullptr;
        ListNode *slow = head;
        ListNode *fast = head;
        while(fast!=NULL && fast->next!=NULL){
            slow = slow->next;
            fast = fast->next->next;

            if(slow == fast){
                slow = head;
                while(slow!=fast){
                    slow = slow->next;
                    fast = fast->next;
                }
                return slow;

            }
        }
        return nullptr;
    }
};



/*
    TEST 1: [3, 2, 0, -4], pos = 1 (Loop back to 2)
    Phase 1: slow and fast meet at node -4.
    Phase 2: slow starts at 3, fast starts at -4. 
             Both move 1 step -> both land on node 2. Match!
    
    TEST 2: [1, 2], pos = -1 (No loop)
    Phase 1: fast hits NULL.
    Return: nullptr.
*/

/*
 * PROBLEM: LINKED LIST CYCLE II
 * * GOAL: 
 * Find the EXACT node where the cycle begins. 
 * If no cycle exists, return NULL.
 *
 * THE STRATEGY: FLOYD'S CYCLE-FINDING ALGORITHM (Two Phases)
 * * PHASE 1: THE DETECTION
 * -----------------------
 * 1. Initialize two pointers, 'slow' and 'fast', both at the 'head'.
 * 2. Move 'slow' by 1 step, and 'fast' by 2 steps.
 * 3. If 'fast' or 'fast->next' becomes NULL, there is no loop -> Return NULL.
 * 4. If 'slow == fast', a cycle exists! 
 * NOTE: They usually meet at a random spot INSIDE the loop, not the entrance.
 *
 * PHASE 2: FINDING THE ENTRANCE
 * -----------------------------
 * 1. Keep 'fast' exactly where the meeting happened in Phase 1.
 * 2. Reset 'slow' back to the 'head' of the list.
 * 3. Move BOTH pointers 1 step at a time now (equal speed).
 * 4. The point where they collide is GUARANTEED to be the start of the cycle.
 * 5. Return that meeting node.
 *
 * WHY PHASE 2 WORKS (THE MATH):
 * -----------------------------
 * Distance from Head to Entrance = L1
 * Distance from Entrance to Phase 1 Meeting Point = L2
 * Remaining distance in loop to get back to Entrance = L3
 *
 * When they meet in Phase 1: Fast traveled twice as far as Slow.
 * 2 * (L1 + L2) = L1 + L2 + (One or more full loops)
 * This math simplifies to show that L1 (Tail) is equal to L3 (Remainder of Loop).
 * Therefore, a pointer from the head and a pointer from the meeting spot 
 * will always meet at the entrance!
 */

// EXAMPLE TRACE:
// List: 1 -> 2 -> 3 -> 4 -> 5 -> (points back to 3)
// Phase 1 Meeting: Slow and Fast might meet at Node 5.
// Phase 2: Reset Slow to 1. Move Slow (1->2->3) and Fast (5->3).
// Result: They collide at Node 3. Return Node 3.