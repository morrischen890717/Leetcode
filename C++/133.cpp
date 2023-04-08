/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
public:
    Node* dfs(Node* curr, unordered_map<int, Node*>& visited){
        if(visited.count(curr->val) > 0)
            return visited[curr->val];
        Node *copy = new Node(curr->val);
        visited[curr->val] = copy;
        int n = curr->neighbors.size();
        for(int i = 0; i < n; i++){
            copy->neighbors.push_back(dfs(curr->neighbors[i], visited));
        }
        return copy;
    }
    Node* cloneGraph(Node* node) {
        if(node == NULL)
            return NULL;
        unordered_map<int, Node*> visited;
        return dfs(node, visited);
    }
};