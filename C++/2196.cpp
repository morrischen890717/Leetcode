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
    TreeNode* createBinaryTree(vector<vector<int>>& descriptions) {
        // using unordered_map
        unordered_map<int, TreeNode*> m;
        unordered_map<int, bool> is_root;
        for(vector<int>& description: descriptions){
            m[description[0]] = m.count(description[0]) ? m[description[0]] : new TreeNode(description[0]);
            m[description[1]] = m.count(description[1]) ? m[description[1]] : new TreeNode(description[1]);
            if(description[2])
                m[description[0]]->left = m[description[1]];
            else
                m[description[0]]->right = m[description[1]];
            if(!is_root.count(description[0]))
                is_root[description[0]] = true;
            is_root[description[1]] = false;
        }
        for(unordered_map<int, bool>::iterator it = is_root.begin(); it != is_root.end(); it++){
            if(it->second)
                return m[it->first];
        }
        return NULL;
    }
};