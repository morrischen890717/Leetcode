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
    ListNode* insertGreatestCommonDivisors(ListNode* head) {
        ListNode *cur = head, *prev = NULL;
        while(cur){
            if(prev)
                prev->next = new ListNode(gcd(prev->val, cur->val), cur);
            prev = cur;
            cur = cur->next;
        }
        return head;
    }
};