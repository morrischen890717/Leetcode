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
    ListNode* oddEvenList(ListNode* head) {
        if(!head || !head->next)
            return head;
        ListNode *oddHead = head, *evenHead = head->next;
        ListNode *oddCurrent = oddHead, *evenCurrent = evenHead;
        bool odd = true;
        head = evenHead->next;
        while(head){
            if(odd){
                oddCurrent->next = head;
                oddCurrent = oddCurrent->next;
            }
            else{
                evenCurrent->next = head;
                evenCurrent = evenCurrent->next;
            }
            head = head->next;
            odd = !odd;
        }
        evenCurrent->next = NULL;
        oddCurrent->next = evenHead;
        return oddHead;
    }
};