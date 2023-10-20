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
        // using two-pointers
        // time complexity: O(M + N), where M == the length of List A and N == the length of List B, space complexity: O(1)
        ListNode *curA = headA, *curB = headB;
        int lenA = 0, lenB = 0;
        while(curA){
            lenA++;
            curA = curA->next;
        }
        while(curB){
            lenB++;
            curB = curB->next;
        }
        curA = headA, curB = headB;
        if(lenA < lenB){
            for(int i = 0; i < lenB - lenA; i++){
                curB = curB->next;
            }
        }
        else if(lenA > lenB){
            for(int i = 0; i < lenA - lenB; i++){
                curA = curA->next;
            }
        }
        while(curA != curB){
            curA = curA->next;
            curB = curB->next;
        }
        return curA;
    }
};