/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* prev;
    Node* next;
    Node* child;
};
*/

class Solution {
public:
    Node* solve(Node* cur){
        if(!cur)
            return NULL;
        Node *next = cur->next, *end = cur;
        if(cur->child){
            end = solve(cur->child);
            cur->next = cur->child;
            cur->child->prev = cur;
            cur->child = NULL;
        }
        if(next){
            end->next = next;
            next->prev = end;
            end = solve(end->next);
        }
        return end;
    }
    Node* flatten(Node* head) {
        // using DFS
        solve(head);
        return head;
    }
};