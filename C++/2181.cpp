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
    ListNode* mergeNodes(ListNode* head) {
        if(!head)
            return NULL;
        if(head->val == 0)
            return mergeNodes(head->next);
        int sum = 0;
        while(head->val){
            sum += head->val;
            head = head->next;
        }
        head->val = sum;
        head->next = mergeNodes(head->next);
        return head;
    }
};