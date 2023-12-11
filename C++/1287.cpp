class Solution {
public:
    int findSpecialInteger(vector<int>& arr) {
        int n = arr.size();
        int curr = arr[0], cnt = 0;
        for(int num: arr){
            if(num != curr){
                if(cnt > n / 4)
                    return curr;
                curr = num;
                cnt = 0;
            }
            cnt++;
        }
        return curr;
    }
};