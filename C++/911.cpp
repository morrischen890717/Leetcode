class TopVotedCandidate {
private:
    int n;
    vector<int> winner, times;
    unordered_map<int, int> votes; // {personId, cnt}
public:
    TopVotedCandidate(vector<int>& persons, vector<int>& times) {
        // time complexity: O(N), space complexity: O(N)
        // reference: https://leetcode.com/problems/online-election/solutions/173382/c-java-python-binary-search-in-times/
        n = times.size();
        winner = vector<int> (n, -1);
        this->times = times;
        int lead = -1;
        for(int i = 0; i < n; i++){
            votes[persons[i]]++;
            if(votes[persons[i]] >= votes[lead])
                lead = persons[i];
            winner[i] = lead;
        }
    }

    int q(int t) {
        int l = 0, r = n - 1;
        while(l <= r){ // binary search
            int mid = l + (r - l) / 2;
            if(times[mid] == t)
                return winner[mid];
            else if(times[mid] < t)
                l = mid + 1;
            else
                r = mid - 1;
        }
        return winner[r];
    }
};

/**
 * Your TopVotedCandidate object will be instantiated and called as such:
 * TopVotedCandidate* obj = new TopVotedCandidate(persons, times);
 * int param_1 = obj->q(t);
 */