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
    ListNode* mergeInBetween(ListNode* list1, int a, int b, ListNode* list2) {
        ListNode *cur = list1, *start, *end = list2;
        for(int i = 0; i < b + 1; i++){
            if(i + 1 == a)
                start = cur;
            cur = cur->next;
        }
        while(end->next){
            end = end->next;
        }
        if(a == 0)
            list1 = list2;
        else
            start->next = list2;
        end->next = cur;
        return list1;
    }
};