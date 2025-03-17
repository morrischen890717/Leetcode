class Solution {
public:
    bool divideArray(vector<int>& nums) {
        int n = nums.size();
        unordered_map<int, bool> m;
        for(int num: nums){
            if(m.count(num))
                m[num] = !m[num];
            else
                m[num] = true;
        }
        for(unordered_map<int, bool>::iterator it = m.begin(); it != m.end(); it++){
            if(it->second)
                return false;
        }
        return true;
    }
};