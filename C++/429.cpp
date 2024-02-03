/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
public:
    vector<vector<int>> levelOrder(Node* root) {
        // using BFS
        if(!root)
            return {};
        vector<vector<int>> ans;
        queue<Node*> q;
        q.push(root);
        while(!q.empty()){
            vector<int> v;
            int size = q.size();
            for(int i = 0; i < size; i++){
                Node *cur = q.front();
                q.pop();
                v.push_back(cur->val);
                for(Node* next: cur->children){
                    q.push(next);
                }
            }
            ans.push_back(v);
        }
        return ans;
    }
};