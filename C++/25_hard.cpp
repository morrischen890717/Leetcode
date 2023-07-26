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
    int cntNodes(ListNode *head){
        int cnt = 0;
        while(head){
            cnt++;
            head = head->next;
        }
        return cnt;
    }
    ListNode* reverseKGroup(ListNode* head, int k) {
        // time complexity: O(N), space complexity: O(1)
        ListNode *cur = head, *prevGroupEnd = NULL;
        ListNode *firstHead = head;
        int n = cntNodes(cur);
        cur = head;
        int cnt = n / k;
        for(int i = 0; i < cnt; i++){
            ListNode *groupEnd = cur, *prev = NULL;
            for(int j = 0; j < k; j++){
                ListNode *nextNode = cur->next;
                cur->next = prev;
                prev = cur;
                cur = nextNode;
            }
            groupEnd->next = cur;
            if(i == 0)
                firstHead = prev;
            else
                prevGroupEnd->next = prev;
            prevGroupEnd = groupEnd;
        }
        return firstHead;
    }
};