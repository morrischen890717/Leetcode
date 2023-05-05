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
    int n;
    ListNode* root;
    Solution(ListNode* head) {
        root = head;
        n = 0;
        while(head != NULL){
            head = head->next;
            n++;
        }
        srand(time(NULL));
    }
    
    int getRandom() {
        int num = rand() % n;
        ListNode* cur = root;
        while(num > 0){
            cur = cur->next;
            num--;
        }
        return cur->val;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(head);
 * int param_1 = obj->getRandom();
 */