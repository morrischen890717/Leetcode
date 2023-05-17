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
    int pairSum(ListNode* head) {
        stack<int> st;
        ListNode *cur = head;
        int n = 0;
        while(cur){
            n++;
            cur = cur->next;
        }
        cur = head;
        for(int i = 0; i < n / 2; i++){
            st.push(cur->val);
            cur = cur->next;
        }
        int ans = INT_MIN;
        for(int i = 0; i < n / 2; i++){
            ans = max(ans, st.top() + cur->val);
            st.pop();
            cur = cur->next;
        }
        return ans;
    }
};