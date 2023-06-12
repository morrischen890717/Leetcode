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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        // almost same as merge sort
        int n = lists.size();
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        ListNode *start = NULL, *prev = NULL;
        for(int i = 0; i < n; i++){
            if(lists[i])
                pq.push({lists[i]->val, i});
        }
        while(!pq.empty()){
            int i = pq.top().second;
            pq.pop();
            if(!prev)
                start = prev = lists[i];
            else{
                prev->next = lists[i];
                prev = prev->next;
            }
            lists[i] = lists[i]->next;
            if(lists[i])
                pq.push({lists[i]->val, i});
        }
        return start;
    }
};