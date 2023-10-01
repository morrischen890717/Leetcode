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
    ListNode* removeZeroSumSublists(ListNode* head) {
        // using prefix sum
        // time complexity: O(N)
        // reference: https://leetcode.com/problems/remove-zero-sum-consecutive-nodes-from-linked-list/solutions/366319/java-c-python-greedily-skip-with-hashmap/
        ListNode *root = new ListNode(0, head); // add root to prevent that head is removed
        ListNode *cur = root;
        unordered_map<int, ListNode*> seen;
        int prefix = 0;
        while(cur){
            prefix += cur->val;
            seen[prefix] = cur;
            cur = cur->next;
        }
        cur = root;
        prefix = 0;
        for(cur = root; cur; cur = cur->next){
            prefix += cur->val;
            if(seen.count(prefix) > 0 && cur != seen[prefix])
                cur->next = seen[prefix]->next;
        }
        return root->next;
    }
};