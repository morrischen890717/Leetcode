/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution {
public:
    Node* connect(Node* root) {
        if(root == NULL)
            return root;
        queue<Node*> q;
        q.push(root);
        Node *cur, *pre;
        int n;
        while(!q.empty()){  // bfs
            n = q.size();
            for(int i = 0; i < n; i++){
                cur = q.front();
                q.pop();
                if(i != 0)
                    pre->next = cur;
                pre = cur;
                if(cur->left != NULL)
                    q.push(cur->left);
                if(cur->right != NULL)
                    q.push(cur->right);
            }
            cur->next = NULL;
        }
        return root;
    }
};