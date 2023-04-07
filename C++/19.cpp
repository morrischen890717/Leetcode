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
        int cnt = 0;
        ListNode *curr = head;
        while(curr != NULL){
            curr = curr->next;
            cnt++;
        }
        if(cnt == n)
            return head->next;
        curr = head;
        while(cnt > n){
            if(cnt - 1 == n){
                curr->next = curr->next->next;
                break;
            }
            curr = curr->next;
            cnt--;
        }
        return head;
    }
};