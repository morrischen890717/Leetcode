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
class BSTIterator {
public:
    stack<TreeNode*> st;  // to reach O(h) memory, where h is the height of the tree
    BSTIterator(TreeNode* root) {
        LeftTree(root);
    }

    void LeftTree(TreeNode* cur){
        while(cur != NULL){
            st.push(cur);
            cur = cur->left;
        }
        return;
    }
    
    int next() {
        TreeNode *cur = st.top();
        st.pop();
        LeftTree(cur->right);
        return cur->val;
    }
    
    bool hasNext() {
        return !st.empty();
    }
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */