class RLEIterator {
private:
    queue<pair<int, int>> q; // {cnt, num}
public:
    RLEIterator(vector<int>& encoding) {
        // time complexity: O(N), space complexity: O(N)
        for(int i = 0; i < encoding.size(); i += 2){
            if(encoding[i] > 0)
                q.push({encoding[i], encoding[i + 1]});
        }
    }
    
    int next(int n) {
        while(!q.empty() && q.front().first < n){
            n -= q.front().first;
            q.pop();
        }
        if(q.empty())
            return -1;
        q.front().first -= n;
        return q.front().second;
    }
};

/**
 * Your RLEIterator object will be instantiated and called as such:
 * RLEIterator* obj = new RLEIterator(encoding);
 * int param_1 = obj->next(n);
 */