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
    int getDecimalValue(ListNode* head) {
        string s;
        while(head){
            s += '0' + head->val;
            head = head->next;
        }
        int ans = 0;
        int j = 1;
        for(int i = s.length() - 1; i >= 0; i--){
            ans += (s[i] - '0') * j;
            j <<= 1;
        }
        return ans;
    }
};