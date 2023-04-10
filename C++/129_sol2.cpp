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
    int sumNumbers(TreeNode* root) { 
        /*
        Using Morris Traversal (Preorder) can reach O(1) space complexity while remaining O(n) time complexity
        */
        TreeNode *cur = root;
        TreeNode *prev;
        int sum = 0;
        int total_sum = 0;
        int depth;
        while(cur != NULL){
            if(cur->left == NULL){  // left side is not there
                sum = sum * 10 + cur->val;  // // preorder(cur->val)
                if(cur->right == NULL)
                    total_sum += sum;
                cur = cur->right;
            }
            else{
                prev = cur->left;
                depth = 1;
                while(prev->right != NULL && prev->right != cur){
                    prev = prev->right;
                    depth++;
                }
                if(prev->right == NULL){  // Root's Left's Rightmost node has no attachments (means first time visit)
                    sum = sum * 10 + cur->val;  // preorder(cur->val)
                    prev->right = cur;
                    cur = cur->left;
                }
                else{  // Root's Left's Rightmost node has threaded attachments (means Root's Left Visited already)
                    prev->right = NULL;
                    if(prev->left == NULL)  // that node is being visited last time
                        total_sum += sum;
                    sum /= pow(10, depth);
                    cur = cur->right;
                }
            }
        }
        return total_sum;
    }
};