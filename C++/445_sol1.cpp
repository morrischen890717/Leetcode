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
    ListNode* reverseListNode(ListNode* head, int& len){
        ListNode *cur = head, *prev_node = NULL, *next_node;
        while(cur != NULL){
            len++;
            next_node = cur->next;
            cur->next = prev_node;
            prev_node = cur;
            cur = next_node;
        }
        return prev_node;
    }
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int len1 = 0, len2 = 0;
        ListNode *reverse_l1 = reverseListNode(l1, len1);
        ListNode *reverse_l2 = reverseListNode(l2, len2);
        ListNode *cur_l1 = reverse_l1, *cur_l2 = reverse_l2;
        int carry = 0;
        ListNode *result_head, *result, *prev_node;
        result_head = (len1 > len2 ? reverse_l1 : reverse_l2);
        result = result_head;
        while(cur_l1 != NULL && cur_l2 != NULL){
            int digit = (cur_l1->val + cur_l2->val + carry) % 10;
            carry = (cur_l1->val + cur_l2->val + carry) / 10;
            result->val = digit;
            cur_l1 = cur_l1->next;
            cur_l2 = cur_l2->next;
            prev_node = result;
            result = result->next;
        }
        while(cur_l1 != NULL){
            int digit = (cur_l1->val + carry) % 10;
            carry = (cur_l1->val + carry) / 10;
            result->val = digit;
            cur_l1 = cur_l1->next;
            prev_node = result;
            result = result->next;
        }
        while(cur_l2 != NULL){
            int digit = (cur_l2->val + carry) % 10;
            carry = (cur_l2->val + carry) / 10;
            result->val = digit;
            cur_l2 = cur_l2->next;
            prev_node = result;
            result = result->next;
        }
        if(carry){
            prev_node->next = new ListNode(carry);
        }
        return reverseListNode(result_head, len1);
    }
};