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
    vector<int> path;
    int cur;
    BSTIterator(TreeNode* root) {
        cur = -1;
        bfs(root);
    }

    void bfs(TreeNode* node){
        if(node != NULL){
            bfs(node->left);
            path.push_back(node->val);
            bfs(node->right);
        }
        return;
    }
    
    int next() {
        cur++;
        return path[cur];
    }
    
    bool hasNext() {
        return ((cur + 1) < path.size() ? true : false);
    }
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */