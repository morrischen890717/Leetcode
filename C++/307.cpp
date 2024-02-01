class NumArray {
private:
    class SegmentTreeNode {
    public:
        int start, end;
        SegmentTreeNode *left, *right;
        int sum;
        SegmentTreeNode(int start, int end){
            this->start = start;
            this->end = end;
            this->left = this->right = NULL;
            this->sum = 0;
        }
    };
    SegmentTreeNode *root;
public:
    SegmentTreeNode* buildSegmentTree(vector<int>& nums, int start, int end){
        SegmentTreeNode *root = new SegmentTreeNode(start, end);
        if(start == end)
            root->sum = nums[start];
        else if(start < end){
            int mid = start + (end - start) / 2;
            root->left = buildSegmentTree(nums, start, mid);
            root->right = buildSegmentTree(nums, mid + 1, end);
            root->sum = root->left->sum + root->right->sum;
        }
        return root;
    }
    NumArray(vector<int>& nums) {
        root = buildSegmentTree(nums, 0, nums.size() - 1);
    }

    void update(SegmentTreeNode* cur, int& index, int& val){
        if(cur->start == index && cur->end == index){
            cur->sum = val;
            return;
        }
        int mid = cur->start + (cur->end - cur->start) / 2;
        if(index > mid)
            update(cur->right, index, val);
        else
            update(cur->left, index, val);
        cur->sum = cur->left->sum + cur->right->sum;
        return;
    }

    void update(int index, int val) {
        update(root, index, val);
        return;
    }
    int sumRange(SegmentTreeNode* cur, int start, int end){
        if(cur->start == start && cur->end == end)
            return cur->sum;
        int mid = cur->start + (cur->end - cur->start) / 2;
        if(start > mid)
            return sumRange(cur->right, start, end);
        else if(end <= mid)
            return sumRange(cur->left, start, end);
        return sumRange(cur->left, start, mid) + sumRange(cur->right, mid + 1, end);
    }
    int sumRange(int left, int right) {
        /*
        using Segment Tree
        time complexity:
            buildSegmentTree: O(4 * N) = O(N) (the total number of nodes in a segment tree is 4 * N at most, where N is the range of the segment tree) 
            update: O(logN)
            sumRange: O(4 * logN) = O(logN)
        reference: https://leetcode.com/problems/range-sum-query-mutable/solutions/75724/17-ms-java-solution-with-segment-tree/
        */
        return sumRange(root, left, right);
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * obj->update(index,val);
 * int param_2 = obj->sumRange(left,right);
 */