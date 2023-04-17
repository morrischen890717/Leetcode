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
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        ListNode *cur = head;
        ListNode *l = head, *r;
        ListNode *start, *end, *start_left, *end_right;
        int cnt = 0;
        for(int i = 1; i < left; i++){
            l = cur;
            cur = cur->next;
        }
        start_left = l;
        start = cur;
        r = cur->next;
        for(int i = 0; i <= right - left; i++){
            r = cur->next;
            cur->next = l;
            l = cur;
            cur = r;
        }
        end = l;
        end_right = cur;
        start->next = end_right;
        if(left != 1)
            start_left->next = end;
        else
            head = end;
        return head;
    }
};