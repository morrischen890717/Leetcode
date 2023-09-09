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
    vector<int> nextLargerNodes(ListNode* head) {
        // using monotonic stack
        // time complexity: O(N), space complexity: O(N)
        vector<int> ans;
        stack<pair<int, int>> st;
        int i = 0;
        ListNode *cur = head;
        while(cur){
            ans.push_back(0);
            while(!st.empty() && st.top().first < cur->val){
                ans[st.top().second] = cur->val;
                st.pop();
            }
            st.push({cur->val, i});
            i++;
            cur = cur->next;
        }
        return ans;
    }
};