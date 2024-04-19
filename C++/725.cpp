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
    vector<ListNode*> splitListToParts(ListNode* head, int k) {
        vector<ListNode*> ans(k, NULL);
        int n = 0;
        ListNode *cur = head;
        while(cur){
            n++;
            cur = cur->next;
        }
        cur = head;
        for(int i = 0; i < k && cur; i++){
            ans[i] = cur;
            int num = n / k + (i < n % k ? 1 : 0);
            for(int j = 0; j < num - 1; j++){
                cur = cur->next;
            }
            ListNode *next = cur->next;
            cur->next = NULL;
            cur = next;
        }
        return ans;
    }
};