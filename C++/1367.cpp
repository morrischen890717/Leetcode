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
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    bool valid(ListNode* head, TreeNode* root){
        if(!head)
            return true;
        if(!root)
            return false;
        return head->val == root->val && (valid(head->next, root->left) || valid(head->next, root->right));
    }
    bool isSubPath(ListNode* head, TreeNode* root) {
        // using recursion
        // reference: https://leetcode.com/problems/linked-list-in-binary-tree/solutions/524821/c-simple-recursion/
        if(!root)
            return false;
        return valid(head, root) || isSubPath(head, root->left) || isSubPath(head, root->right);
    }
};