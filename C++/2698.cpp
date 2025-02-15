class Solution {
public:
    bool valid(int target, string str){
        if(target == 0 && str.empty())
            return true;
        if(target < 0)
            return false;
        int len = str.length();
        for(int i = 1; i <= str.length(); i++){
            int num = stoi(str.substr(0, i));
            if(valid(target - num, str.substr(i)))
                return true;
        }
        return false;
    }
    int punishmentNumber(int n) {
        int ans = 0;
        for(int i = 1; i <= n; i++){
            int num = i * i;
            if(valid(i, to_string(num)))
                ans += num;
        }
        return ans;
    }
};