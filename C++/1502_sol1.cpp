class Solution {
public:
    bool canMakeArithmeticProgression(vector<int>& arr) {
        // time complexity: O(N)
        int n = arr.size();
        int min_num = INT_MAX, max_num = INT_MIN;
        for(int num: arr){
            min_num = min(min_num, num);
            max_num = max(max_num, num);
        }
        if((max_num - min_num) % (n - 1) != 0)
            return false;
        int d = (max_num - min_num) / (n - 1);
        int i = 0;
        while(i < n){
            if(arr[i] == min_num + i * d)
                i++;
            else if((arr[i] - min_num) % d != 0)
                return false;
            else{
                int pos = (arr[i] - min_num) / d; // correct position
                if(arr[i] == arr[pos]) // there are two elements with same value(will cause infinite loop)
                    return false;
                else
                    swap(arr[i], arr[pos]);
            }
        }
        return true;
    }
};