class Solution {
public:
    unordered_map<int, bool> flipped;
    int r, c;
    Solution(int m, int n) {
        r = m;
        c = n;
        srand(time(NULL));
    }
    
    vector<int> flip() {
        int num = rand() % (r * c);
        while(flipped[num] == true){
            num = rand() % (r * c);
        }
        flipped[num] = true;
        int i = num / c, j = num % c;
        return {i, j};
    }
    
    void reset() {
        flipped.clear();
        return;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(m, n);
 * vector<int> param_1 = obj->flip();
 * obj->reset();
 */