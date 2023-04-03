/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        unordered_map<Node*, Node*> copy;
        Node *curr = head;
        while(curr != NULL){
            copy[curr] = new Node(curr->val);
            curr = curr->next;
        }
        copy[NULL] = NULL;
        curr = head;
        while(curr != NULL){
            copy[curr]->next = copy[curr->next];
            copy[curr]->random = copy[curr->random];
            curr = curr->next;
        }
        return copy[head];
    }
};