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
    ListNode* middleNode(ListNode* head) {
        int cnt = 0;
        ListNode *cur = head;
        while(cur){
            cur = cur->next;
            cnt++;
        }
        cnt = cnt / 2;
        cur = head;
        for(int i = 0; i < cnt; i++){
            cur = cur->next;
        }
        return cur;
    }
};