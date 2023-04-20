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
    Node* connect(Node* root) {  // bfs with space optimization
        if(!root)
            return root;
        root->next = NULL;
        Node *head = root, *cur;
        while(head){
            cur = head;
            while(cur){
                if(cur->left){
                    cur->left->next = cur->right;
                    if(cur->next){
                        cur->right->next = cur->next->left;
                    }
                    else{
                        cur->right->next = NULL;
                    }
                }
                cur = cur->next;
            }
            head = head->left;
        }
        return root;
    }
};