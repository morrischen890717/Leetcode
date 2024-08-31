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
    bool dfs(TreeNode* root, int value, string& s){
        if(!root)
            return false;
        if(root->val == value)
            return true;
        if(dfs(root->left, value, s)){
            s += 'L';
            return true;   
        }
        else if(dfs(root->right, value, s)){
            s += 'R';
            return true;
        }
        return false;
    }
    string getDirections(TreeNode* root, int startValue, int destValue) {
        // using DFS
        string start, end;
        dfs(root, startValue, start);
        dfs(root, destValue, end);
        reverse(start.begin(), start.end());
        reverse(end.begin(), end.end());
        int len1 = start.length(), len2 = end.length();
        string ans;
        for(int i = 0; i < len1 && i < len2; i++){
            if(start[i] != end[i]){
                ans = string (len1 - i, 'U');
                ans += end.substr(i);
                return ans;
            }
        }
        if(len1 > len2)
            ans = string (len1 - len2, 'U');
        else if(len1 < len2)
            ans = end.substr(len1);
        return ans;
    }
};