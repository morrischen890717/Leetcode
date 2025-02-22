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
    TreeNode* solve(string& traversal, int& i, int h){
        if(i == traversal.length())
            return NULL;
        int tmp = i, cnt = 0;
        while(traversal[i] == '-'){
            cnt++;
            i++;
        }
        if(cnt != h){
            i = tmp;
            return NULL;
        }
        string s;
        while(i < traversal.length() && traversal[i] != '-'){
            s += traversal[i];
            i++;
        }
        TreeNode *res = new TreeNode(stoi(s));
        res->left = solve(traversal, i, h + 1);
        res->right = solve(traversal, i, h + 1);
        return res;
    }
    TreeNode* recoverFromPreorder(string traversal) {
        int i = 0;
        return solve(traversal, i, 0);
    }
};