class Solution {
public:
    vector<int> partitionLabels(string s) {
        /*
        using Greedy
        time complexity: O(N), space complexity:(N)
        if there is no overlap, a 'start' is always be followed by its corresponding 'end', so 'cnt' will never be more than 1. 
        If there is a overlap, you will see two consecutive starts.  (e.g. startA...startB...endA...endB)
        So, if there is only a double overlap, 'cnt' can grow to 2. Similarly, if there is a triple overlap then 'cnt' can go to 3. (e.g. startA...startB...startC...endB...endC...endA)
        */
        vector<int> ans;
        int len = s.length();
        int cnt = 0;
        vector<int> v(len, 0);
        vector<bool> start(26, false);
        vector<bool> end(26, false);
        for(int i = 0; i < len; i++){
            if(!start[s[i] - 'a']){
                v[i]++; // start of char s[i], +1
                start[s[i] - 'a'] = true;
            }
            if(!end[s[len - 1 - i] - 'a']){
                v[len - 1 - i]--; // end of char s[i], -1
                end[s[len - 1 - i] - 'a'] = true;
            }
        }
        int prevCut = -1;
        for(int i = 0; i < len; i++){
            cnt += v[i];
            if(cnt == 0){
                ans.push_back(i - prevCut);
                prevCut = i;
            }
        }
        return ans;
    }
};