class Node {
public:
    int val;
    int left_cnt;
    Node *left, *right;
    Node(int val = 0){
        this->val = val;
        left = right = NULL;
        left_cnt = 0;
    }
};

class Solution {
public:
    int count(Node* root, int val){
        if(!root)
            return 0;
        if(val < root->val)
            return count(root->left, val);
        return 1 + root->left_cnt + count(root->right, val);
    }
    Node* insert(Node* root, int val){
        if(!root)
            return new Node(val);
        if(val < root->val){
            root->left_cnt++;
            root->left = insert(root->left, val);
        }
        else
            root->right = insert(root->right, val);
        return root;
    }
    Node* remove(Node* root, int val){
        if(!root)
            return NULL;
        if(val == root->val){
            Node* rightmost = root->left;
            if(!rightmost)
                return root->right;
            while(rightmost->right){
                rightmost = rightmost->right;
            }
            rightmost->right = root->right;
            return root->left;
        }
        else if(val < root->val){
            root->left_cnt--;
            root->left = remove(root->left, val);
        }
        else
            root->right = remove(root->right, val);
        return root;
    }
    int numTeams(vector<int>& rating) {
        // using binary search tree
        // time complexity: O(NlogN) (average), if we want to get O(NlogN) in the worst case, we need to balance the binary search tree when we built the tree
        // space complexity: O(N)
        // reference: https://leetcode.com/problems/count-number-of-teams/solutions/554795/c-java-o-n-n-and-o-n-log-n/?envType=daily-question&envId=2024-07-29
        int ans = 0;
        int n = rating.size();
        Node *l = new Node(rating.front()), *r = new Node(rating.back());
        for(int i = 2; i < n - 1; i++){
            insert(r, rating[i]);
        }
        for(int i = 1; i < n - 1; i++){
            int left_small = count(l, rating[i]), left_large = i - left_small;
            int right_small = count(r, rating[i]), right_large = n - 1 - i - right_small;
            ans += left_small * right_large + left_large * right_small;
            insert(l, rating[i]);
            remove(r, rating[i + 1]);
        }
        return ans;
    }
};