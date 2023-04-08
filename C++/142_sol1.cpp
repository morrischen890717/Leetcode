/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *detectCycle(ListNode *head) { // using Floyd Cycle Detection Algorithm to make space complexity be O(1)
        ListNode *fast, *slow;
        fast = slow = head;
        while(fast != NULL && fast->next != NULL){
            slow = slow->next;      // slow goes one step while fast goes two steps every time
            fast = fast->next->next;
            if(slow == fast){
                /*
                Assume the distance of head to the node where the cycle begins
                is m, the distance of the node where the cycle begins to the 
                node where slow and fast meet is n, the distance of the node 
                where slow and fast meet to the node where the cycle begins is 
                k. Slow goes m+n steps while fast goes m+2n+k steps until the 
                first time they meet each other. And based on the setting that 
                slow goes one step while fast goes two steps every time, we can 
                know that 2(m+n) = m+2n+k => m=k, so this approach(set slow to 
                head) will work.
                */
                slow = head;
                while(slow != fast){
                    slow = slow->next;
                    fast = fast->next;
                }
                return slow;
            }
        }
        return NULL;
    }
};