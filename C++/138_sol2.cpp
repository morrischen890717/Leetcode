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
        map<Node*, vector<Node*>> future;
        map<Node*, Node*> m;
        Node *copy = head;
        Node *pre = NULL;
        Node *ans;
        while(copy != NULL){
            Node *curr = new Node(copy->val);
            if(pre == NULL)
                ans = curr;
            else
                pre->next = curr;
            pre = curr;
            m[copy] = curr;
            cout << copy->val << '\n';
            if(m.count(copy->random) > 0)
                curr->random = m[copy->random];
            else if(future.count(copy->random) > 0)
                future[copy->random].push_back(curr);
            else
                future[copy->random] = {curr};

            if(future.count(copy) > 0){
                for(int i = 0; i < future[copy].size(); i++){
                    future[copy][i]->random = curr;
                }
                future.erase(copy);
            }
            
            copy = copy->next;
        }
        return ans;
    }
};