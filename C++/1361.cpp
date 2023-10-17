class Solution {
public:
    int findRoot(int n, vector<int>& leftChild, vector<int>& rightChild, vector<bool>& visited){
        for(int i = 0; i < n; i++){
            if(leftChild[i] != -1)
                visited[leftChild[i]] = true;
            if(rightChild[i] != -1)
                visited[rightChild[i]] = true;
        }
        int root = -1;
        for(int i = 0; i < n; i++){
            if(!visited[i]){
                if(root == -1)
                    root = i;
                else
                    return -1;
            }
        }
        return root;
    }
    bool dfs(vector<int>& leftChild, vector<int>& rightChild, int i, int& visitedCnt){
        if(i == -1)
            return true;
        else if(i == -2) // visited
            return false;
        visitedCnt++;
        int l = leftChild[i], r = rightChild[i];
        leftChild[i] = rightChild[i] = -2;
        return dfs(leftChild, rightChild, l, visitedCnt) && dfs(leftChild, rightChild, r, visitedCnt);
    }
    bool validateBinaryTreeNodes(int n, vector<int>& leftChild, vector<int>& rightChild) {
        // using DFS
        // time complexity: O(N), space complexity: O(N)
        vector<bool> visited(n, false);
        int root = findRoot(n, leftChild, rightChild, visited);
        if(root == -1)
            return false;
        int visitedCnt = 0;
        return dfs(leftChild, rightChild, root, visitedCnt) && visitedCnt == n;
    }
};