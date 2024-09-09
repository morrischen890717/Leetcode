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
    vector<vector<int>> spiralMatrix(int m, int n, ListNode* head) {
        vector<vector<int>> ans(m, vector<int> (n, -1));
        vector<int> dirs = {0, 1, 0, -1, 0};
        int dir = 0;
        int i = 0, j = 0;
        while(head){
            ans[i][j] = head->val;
            head = head->next;
            int new_i = i + dirs[dir], new_j = j + dirs[dir + 1];
            if(new_i < 0 || new_i >= m  || new_j < 0 || new_j >= n || ans[new_i][new_j] != -1)
                dir = (dir + 1) % 4;
            i += dirs[dir];
            j += dirs[dir + 1];
        }
        return ans;
    }
};