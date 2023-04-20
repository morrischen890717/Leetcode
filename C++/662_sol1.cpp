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
    void dfs(TreeNode* node, vector<int>& l_min, vector<int>& r_max, int depth, long long id){
        if(l_min.size() <= depth){
            l_min.push_back(id);  // the leftmost node in depth i will be the first node which meet in depth i
            r_max.push_back(id);
        }
        else{
            r_max[depth] = id;  // when meet new node in depth i, then update the rightmost node in depth i
        }
        /*
        let the id of node->left and node->right (next level) be (the distance 
        from current node to leftmost node)*2 and (the distance from current node 
        to leftmost node)*2+1, respectively
        */
        if(node->left != NULL)
            dfs(node->left, l_min, r_max, depth + 1, (id - l_min[depth]) * 2);
        if(node->right != NULL)
            dfs(node->right, l_min, r_max, depth + 1, (id - l_min[depth]) * 2 + 1);
        return;
    }
    int widthOfBinaryTree(TreeNode* root) {
        vector<int> l_min, r_max; // l_min and r_max record leftmost node's id and rightmost node's id in each depth, respectively
        dfs(root, l_min, r_max, 0, 0);
        int ans = 0;
        for(int i = 0; i < l_min.size(); i++){
            ans = max(ans, r_max[i] - l_min[i] + 1);
        }
        return ans;
    }
};