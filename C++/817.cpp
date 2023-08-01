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
    int numComponents(ListNode* head, vector<int>& nums) {
        /*
        using unordered_set
        reference: https://leetcode.com/problems/linked-list-components/solutions/123842/c-java-python-easy-and-concise-solution-with-explanation/
        */
        int ans = 0;
        unordered_set<int> s(nums.begin(), nums.end());
        while(head){
            if(s.count(head->val) && (!head->next || !s.count(head->next->val)))
                ans++;
            head = head->next;
        }
        return ans;
    }
};