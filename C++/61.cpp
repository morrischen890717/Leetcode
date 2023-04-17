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
    ListNode* rotateRight(ListNode* head, int k) {
        if(head == NULL)
            return NULL;
        int cnt = 0;
        ListNode *cur = head;
        ListNode *end;
        while(cur != NULL){
            cnt++;
            end = cur;
            cur = cur->next;
        }
        k %= cnt;
        if(k == 0)
            return head;
        end->next = head;
        cur = head;
        for(int i = 0; i < cnt - k; i++){
            end = cur;
            cur = cur->next;
        }
        end->next = NULL;
        return cur;
    }
};