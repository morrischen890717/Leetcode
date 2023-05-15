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
    ListNode* swapNodes(ListNode* head, int k) {
        ListNode *cur = head;
        ListNode *node1 = NULL, *node2 = NULL;
        ListNode *cur_next_k = cur;
        for(int i = 0; i < k; i++){
            cur_next_k = cur_next_k->next;
        }
        int n = 0;
        while(!node1 || !node2){
            n++;
            if(n == k)
                node1 = cur;
            if(!cur_next_k && !node2)
                node2 = cur;
            cur = cur->next;
            cur_next_k = (cur_next_k ? cur_next_k->next : NULL);
        }
        int tmp = node1->val;
        node1->val = node2->val;
        node2->val = tmp;
        return head;
    }
};