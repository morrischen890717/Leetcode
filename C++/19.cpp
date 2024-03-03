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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode *cur = head;
        int cnt = 0;
        while(cur){
            cnt++;
            cur = cur->next;
        }
        if(cnt == n)
            return head->next;
        cur = head;
        for(int i = 0; i < cnt - n - 1; i++){
            cur = cur->next;
        }
        cur->next = cur->next->next;
        return head;
    }
};