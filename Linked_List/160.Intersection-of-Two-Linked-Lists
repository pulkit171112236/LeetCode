/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode *a, *b;
        
        a = headA;
        b = headB;
        while (a!=b) {
            a = a->next;
            b = b->next;
            
            // Any time they collide or reach end together without colliding 
            // then return any one of the pointers.
            if (a == b) return a;
            
            else if (a == nullptr) a = headB;
            else if (b == nullptr) b = headA;
        }
        return a;
    }
};
