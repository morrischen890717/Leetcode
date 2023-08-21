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
    ListNode* partition(ListNode* head, int x) {
        // using two-pointers
        ListNode *current = head;
        ListNode *head_l = NULL;
        ListNode *pre_l;
        ListNode *head_g = NULL;
        ListNode *pre_g;
        while(current != NULL){
            if(current->val < x){
                if(head_l == NULL){
                    head_l = current;
                    pre_l = head_l;
                }
                else{
                    pre_l->next = current;
                    pre_l = current;
                }
            }
            else {
                if(head_g == NULL){
                    head_g = current;
                    pre_g = head_g;
                }
                else{
                    pre_g->next = current;
                    pre_g = current;
                }
            }
            current = current->next;
        }
        if(head_l == NULL)
            return head_g;
        else if(head_g == NULL)
            return head_l;
        else{
            pre_l->next = head_g;
            pre_g->next = NULL;
        }
        return head_l;
    }
};