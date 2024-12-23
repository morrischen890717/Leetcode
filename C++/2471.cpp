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
    int minimumOperations(TreeNode* root) {
        int ans = 0;
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()){
            int n = q.size();
            vector<pair<int, int>> v;
            for(int i = 0; i < n; i++){
                TreeNode *cur = q.front();
                q.pop();
                v.push_back({cur->val, i});
                if(cur->left)
                    q.push(cur->left);
                if(cur->right)
                    q.push(cur->right);
            }
            sort(v.begin(), v.end());
            for(int i = 0; i < n; i++){
                while(v[i].second != i){
                    ans++;
                    swap(v[i], v[v[i].second]);
                }
            }
        }
        return ans;
    }
};