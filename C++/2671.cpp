class FrequencyTracker {
public:
    unordered_map<int, int> cnt;
    unordered_map<int, int> f;
    FrequencyTracker() {
        
    }
    
    void add(int number) {
        if(f[cnt[number]] > 0)
            f[cnt[number]]--;
        cnt[number]++;
        f[cnt[number]]++;
        return;
    }
    
    void deleteOne(int number) {
        if(cnt[number] > 0){
            f[cnt[number]]--;
            cnt[number]--; 
            f[cnt[number]]++;
        }
        return;
    }
    
    bool hasFrequency(int frequency) {
        return f[frequency] > 0;
    }
};

/**
 * Your FrequencyTracker object will be instantiated and called as such:
 * FrequencyTracker* obj = new FrequencyTracker();
 * obj->add(number);
 * obj->deleteOne(number);
 * bool param_3 = obj->hasFrequency(frequency);
 */