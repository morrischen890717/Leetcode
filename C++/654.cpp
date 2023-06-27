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
    TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
        /*
        using vector as monotonic stack
        time complexity: O(N)
        reference: https://leetcode.com/problems/maximum-binary-tree/solutions/106146/c-o-n-solution/
        */
        int n = nums.size();
        vector<TreeNode*> st; // always be descending
        for(int i = 0; i < n; i++){
            TreeNode *cur = new TreeNode(nums[i]);
            while(!st.empty() && nums[i] > st.back()->val){
                cur->left = st.back();
                st.pop_back();
            }
            if(!st.empty())
                st.back()->right = cur;
            st.push_back(cur);
        }
        return st[0];
    }
};