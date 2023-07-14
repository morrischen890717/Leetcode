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
    int countNodes(ListNode* head){
        ListNode *cur = head;
        int n = 0;
        while(cur){
            n++;
            cur = cur->next;
        }
        return n;
    }
    vector<ListNode*> splitListToParts(ListNode* head, int k) {
        vector<ListNode*> ans(k, NULL);
        int n = countNodes(head);
        int size = n / k;
        int oneMore = n % k;
        ListNode *cur = head, *prev = cur;
        for(int i = 0; i < k; i++, oneMore--){
            ans[i] = cur;
            for(int j = 0; j < (oneMore > 0 ? size + 1 : size); j++){
                prev = cur;
                cur = cur->next;
            }
            if(prev)
                prev->next = NULL;
        }
        return ans;
    }
};