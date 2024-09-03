class FreqStack {
private:
    unordered_map<int, int> freq;
    unordered_map<int, stack<int>> m;
    int max_freq;
public:
    FreqStack() {
        // using unordered_map and stack
        // time complexity: O(1), space complexity: O(N)
        // reference: https://leetcode.com/problems/maximum-frequency-stack/solutions/163410/c-java-python-o-1/
        max_freq = 0;
    }
    
    void push(int val) {
        max_freq = max(max_freq, ++freq[val]);
        m[freq[val]].push(val);
        return;
    }
    
    int pop() {
        int res = m[max_freq].top();
        m[max_freq].pop();
        freq[res]--;
        if(m[max_freq].size() == 0)
            max_freq--;
        return res;
    }
};

/**
 * Your FreqStack object will be instantiated and called as such:
 * FreqStack* obj = new FreqStack();
 * obj->push(val);
 * int param_2 = obj->pop();
 */