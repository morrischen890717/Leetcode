class Solution {
public:
    int sum;
    vector<int> prefix; // prefix sum
    Solution(vector<int>& w) {
        prefix = vector<int> (w.size());
        sum = 0;
        for(int i = 0; i < w.size(); i++){
            sum += w[i];
            prefix[i] = sum;
        }
        srand(time(NULL));
    }
    
    int pickIndex() {
        int pick = rand() % sum + 1;
        int l = 0, r = prefix.size() - 1;
        while(l <= r){
            int mid = l + (r - l) / 2;
            if(prefix[mid] == pick)
                return mid;
            else if(prefix[mid] < pick)
                l = mid + 1;
            else
                r = mid - 1;
        }
        return l;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(w);
 * int param_1 = obj->pickIndex();
 */