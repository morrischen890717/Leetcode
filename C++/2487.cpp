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
    ListNode* removeNodes(ListNode* head) {
        // using monotonic stack
        stack<ListNode*> st;
        while(head){
            while(!st.empty() && head->val > st.top()->val){
                st.pop();
            }
            st.push(head);
            head = head->next;
        }
        ListNode *tmp = NULL;
        while(!st.empty()){
            st.top()->next = tmp;
            tmp = st.top();
            st.pop();
        }
        return tmp;
    }
};