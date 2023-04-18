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
    ListNode* deleteDuplicates(ListNode* head) {
        if(head == NULL)
            return head;
        ListNode *cur = head;
        ListNode *end = head;
        int dup_num = -10000;
        while(cur != NULL){
            if(cur->val == dup_num || (cur->next != NULL && cur->val == cur->next->val)){
                if(cur->val == head->val){
                    head = head->next;
                }
                dup_num = cur->val;
            }
            else{
                if(end != cur)
                    end->next = cur;
                end = cur;
            }
            cur = cur->next;
        }
        end->next = NULL;
        return head;
    }
};