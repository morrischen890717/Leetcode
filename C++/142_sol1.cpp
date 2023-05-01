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
                node where slow and fast meet is p, the distance of the node 
                where slow and fast meet to the node where the cycle begins is 
                k. Slow goes m+p steps while fast goes m+p+n*(p+k) steps until the first time they meet each other.
                And based on the setting that slow goes one step while fast 
                goes two steps every time, we can know that 2(m+p) = m+p+n*(p+k) => 
                m+p = n*(p+k) => m+p = (p+k) + (n-1)*(p+k) => m = k + (n-1)*(p+k), 
                so if slow start from head and fast start from the first node 
                they meet, and two pointers both goes one step a time, then 
                slow goes m steps to the node where cycle begins and fast goes 
                n-1 times cycle and goes k steps to the node where cycle 
                begins, so this approach(set slow to head) will work.
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