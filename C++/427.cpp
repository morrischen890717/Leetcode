/*
// Definition for a QuadTree node.
class Node {
public:
    bool val;
    bool isLeaf;
    Node* topLeft;
    Node* topRight;
    Node* bottomLeft;
    Node* bottomRight;
    
    Node() {
        val = false;
        isLeaf = false;
        topLeft = NULL;
        topRight = NULL;
        bottomLeft = NULL;
        bottomRight = NULL;
    }
    
    Node(bool _val, bool _isLeaf) {
        val = _val;
        isLeaf = _isLeaf;
        topLeft = NULL;
        topRight = NULL;
        bottomLeft = NULL;
        bottomRight = NULL;
    }
    
    Node(bool _val, bool _isLeaf, Node* _topLeft, Node* _topRight, Node* _bottomLeft, Node* _bottomRight) {
        val = _val;
        isLeaf = _isLeaf;
        topLeft = _topLeft;
        topRight = _topRight;
        bottomLeft = _bottomLeft;
        bottomRight = _bottomRight;
    }
};
*/

class Solution {
public:
    Node* solve(vector<vector<int>>& grid, int start_r, int end_r, int start_c, int end_c){
        Node *cur = new Node();
        if(start_r == end_r){
            cur->isLeaf = true;
            cur->val = grid[start_r][start_c];
        }
        else{
            int mid_r = start_r + (end_r - start_r) / 2, mid_c = start_c + (end_c - start_c) / 2;
            cur->topLeft = solve(grid, start_r, mid_r, start_c, mid_c);
            cur->topRight = solve(grid, start_r, mid_r, mid_c + 1, end_c);
            cur->bottomLeft = solve(grid, mid_r + 1, end_r, start_c, mid_c);
            cur->bottomRight = solve(grid, mid_r + 1, end_r, mid_c + 1, end_c);
            if(cur->topLeft->isLeaf && cur->topRight->isLeaf && cur->bottomLeft->isLeaf && cur->bottomRight->isLeaf && cur->topLeft->val == cur->topRight->val && cur->topRight->val == cur->bottomLeft->val && cur->bottomLeft->val == cur->bottomRight->val){
                cur->isLeaf = true;
                cur->val = cur->topLeft->val;
                cur->topLeft = cur->topRight = cur->bottomLeft = cur->bottomRight = NULL;
            }
        }
        return cur;
    }
    Node* construct(vector<vector<int>>& grid) {
        // using Divide-and-Conquer
        int n = grid.size();
        return solve(grid, 0, n - 1, 0, n - 1);
    }
};