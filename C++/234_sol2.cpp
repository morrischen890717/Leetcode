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
    bool isPalindrome(ListNode* head) {
        int n = 0;
        ListNode *cur = head;
        while(cur){
            n++;
            cur = cur->next;
        }
        cur = head;
        ListNode *prev = NULL;
        for(int i = 0; i < n / 2; i++){
            ListNode *next = cur->next;
            cur->next = prev;
            prev = cur;
            cur = next;
        }
        if(n % 2)
            cur = cur->next;
        for(int i = 0; i < n / 2; i++){
            if(cur->val != prev->val)
                return false;
            cur = cur->next;
            prev = prev->next;
        }
        return true;
    }
};