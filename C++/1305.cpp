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
    void pushLeftChild(TreeNode *root, stack<TreeNode*>& st){
        // keep adding left child into stack
        while(root){
            st.push(root);
            root = root->left;
        }
        return;
    }
    vector<int> getAllElements(TreeNode* root1, TreeNode* root2) {
        // using stack
        vector<int> ans;
        stack<TreeNode*> st1, st2;
        pushLeftChild(root1, st1);
        pushLeftChild(root2, st2);
        while(!st1.empty() || !st2.empty()){
            int val1 = st1.empty() ? INT_MAX : st1.top()->val;
            int val2 = st2.empty() ? INT_MAX : st2.top()->val;
            if(val1 < val2){
                ans.push_back(val1);
                TreeNode *rightChild = st1.top()->right;
                st1.pop();
                pushLeftChild(rightChild, st1);
            }
            else{
                ans.push_back(val2);
                TreeNode *rightChild = st2.top()->right;
                st2.pop();
                pushLeftChild(rightChild, st2);
            }
        }
        return ans;
    }
};