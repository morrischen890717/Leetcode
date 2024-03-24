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
    void reorderList(ListNode* head) {
        // time complexity: O(N), space complexity: O(1)
        ListNode *slow = head, *fast = head->next;
        while(fast && fast->next){
            slow = slow->next;
            fast = fast->next->next;
        }
        ListNode *reversedCur = slow->next, *prev = NULL;
        slow->next = NULL;
        while(reversedCur){
            ListNode *next = reversedCur->next;
            reversedCur->next = prev;
            prev = reversedCur;
            reversedCur = next;
        }
        ListNode *cur = head;
        while(prev){
            ListNode *next = prev->next;
            prev->next = cur->next;
            cur->next = prev;
            cur = cur->next->next;
            prev = next;
        }
        return;
    }
};