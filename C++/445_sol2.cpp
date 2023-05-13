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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        stack<int> st1, st2;
        while(l1){
            st1.push(l1->val);
            l1 = l1->next;
        }
        while(l2){
            st2.push(l2->val);
            l2 = l2->next;
        }
        int carry = 0;
        ListNode *head, *prev = NULL;
        while(!st1.empty() && !st2.empty()){
            int sum = st1.top() + st2.top() + carry;
            st1.pop();
            st2.pop();
            int digit = sum % 10;
            carry = sum / 10;
            head = new ListNode(digit);
            if(prev)
                head->next = prev;
            prev = head;
        }
        while(!st1.empty()){
            int sum = st1.top() + carry;
            st1.pop();
            int digit = sum % 10;
            carry = sum / 10;
            head = new ListNode(digit);
            head->next = prev;
            prev = head;
        }
        while(!st2.empty()){
            int sum = st2.top() + carry;
            st2.pop();
            int digit = sum % 10;
            carry = sum / 10;
            head = new ListNode(digit);
            head->next = prev;
            prev = head;
        }
        if(carry){
            head = new ListNode(carry);
            head->next = prev;
            prev = head;
        }
        return head;
    }
};