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
    bool is_critical(int a, int b, int c){
        return a < b && b > c || a > b && b < c;
    }
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
        int min_dist = INT_MAX, max_dist = INT_MIN;
        int first_point = -1, last_point = -1;
        int prev = -1;
        int id = 0;
        while(head->next){
            if(prev != -1 && is_critical(prev, head->val, head->next->val)){
                if(first_point == -1)
                    first_point = id;
                if(last_point != -1)
                    min_dist = min(min_dist, id - last_point);
                last_point = id;
            }
            prev = head->val;
            head = head->next;
            id++;
        }
        if(first_point == last_point)
            return {-1, -1};
        max_dist = last_point - first_point;
        return {min_dist, max_dist};
    }
};