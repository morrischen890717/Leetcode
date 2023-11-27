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
    ListNode* swapPairs(ListNode* head) {
        ListNode *curr = head;
        ListNode *pre_pair_end;
        ListNode *curr_pair_end;
        ListNode *final_head;
        int cnt = 0;
        while(curr != NULL){
            cnt++;
            if(cnt % 2){
                curr_pair_end = curr;
            }
            else{
                if(cnt == 2){
                    final_head = curr;
                }
                else{
                    pre_pair_end->next = curr;
                }
                curr_pair_end->next = curr->next;
                curr->next = curr_pair_end;
                curr = curr->next;
                pre_pair_end = curr;
            }
            curr = curr->next;
        }
        return final_head;
    }
};