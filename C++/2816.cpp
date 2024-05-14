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
class Solution {
public:
    ListNode* solve(ListNode* cur){
        if(!cur)
            return NULL;
        cur->next = solve(cur->next);
        int carry = 0;
        if(cur->next && cur->next->val >= 10){
            carry = cur->next->val / 10;
            cur->next->val %= 10;
        }
        cur->val = 2 * cur->val + carry;
        return cur;
    }
    ListNode* doubleIt(ListNode* head) {
        head = solve(head);
        if(head->val >= 10){
            int carry = head->val / 10;
            head->val %= 10;
            head = new ListNode(carry, head);
        }
        return head;
    }
};