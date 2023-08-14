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
    TreeNode* solve(vector<int>& pre, vector<int>& id, int start, int end){
        if(start == end)
            return new TreeNode(pre[start]);
        else if(start > end)
            return NULL;
        int r; // starting index for right subtree
        for(r = start + 2; r <= end; r++){
            if(id[pre[start + 1]] < id[pre[r]])
                break;
        }
        return new TreeNode(pre[start], solve(pre, id, start + 1, r - 1), solve(pre, id, r, end));
    }
    TreeNode* constructFromPrePost(vector<int>& preorder, vector<int>& postorder) {
        // using Divide-and-Conquer
        int n = preorder.size();
        vector<int> id(n + 1);
        for(int i = 0; i < n; i++){
            id[postorder[i]] = i;
        }
        return solve(preorder, id, 0, n - 1);
    }
};