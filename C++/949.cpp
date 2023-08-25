class Solution {
public:
    int convertToMins(int i, int j, int k, int t){
        if(i * 10 + j > 23 || k * 10 + t > 59)
            return -1;
        int mins = (i * 10 + j) * 60 + k * 10 + t;
        return mins;
    }
    string largestTimeFromDigits(vector<int>& arr) {
        string ans = "";
        vector<int> cnt(10, 0);
        int n = arr.size();
        int maxMins = -1;
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                for(int k = 0; k < n; k++){
                    for(int t = 0; t < n; t++){
                        if(i == j || i == k || i == t || j == k || j == t || k == t)
                            continue;
                        int time = convertToMins(arr[i], arr[j], arr[k], arr[t]);
                        if(time > maxMins){
                            maxMins = time;
                            ans = to_string(arr[i]) + to_string(arr[j]) + ":" + to_string(arr[k]) + to_string(arr[t]);
                        }
                    }
                }
            }
        }
        return ans;
    }
};