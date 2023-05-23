class KthLargest {
public:
    priority_queue<int, vector<int>, greater<int>> stream;
    int kth;
    KthLargest(int k, vector<int>& nums) {
        kth = k;
        for(int i = 0; i < nums.size(); i++){
            stream.push(nums[i]);
            if(stream.size() > k)
                stream.pop();
        }
    }
    
    int add(int val) {
        stream.push(val);
        if(stream.size() > kth)
            stream.pop();
        return stream.top();
    }
};

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */