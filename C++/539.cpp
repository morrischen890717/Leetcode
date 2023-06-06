class Solution {
public:
    int convertToMinutes(string t){
        int h = stoi(t.substr(0, 2));
        int m = stoi(t.substr(3, 2));
        return h * 60 + m;
    }
    int findMinDifference(vector<string>& timePoints) {
        int n = timePoints.size();
        vector<bool> bucket(24 * 60, false);
        int ans = INT_MAX;
        int last = -1e7, first = 1e7;
        for(int i = 0; i < n; i++){
            if(bucket[convertToMinutes(timePoints[i])])
                return 0;
            bucket[convertToMinutes(timePoints[i])] = true;;
        }
        for(int i = 0; i < bucket.size(); i++){
            if(bucket[i]){
                if(first == 1e7)
                    first = i;
                ans = min(ans, i - last);
                last = i;
            }
        }
        ans = min(ans, first + 24 * 60 - last); // e.g. 00:00(24:00) - 23:59 = 1
        return ans;
    }
};