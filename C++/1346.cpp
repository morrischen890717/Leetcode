class Solution {
public:
    bool checkIfExist(vector<int>& arr) {
        unordered_set<int> s;
        for(int num: arr){
            if(num == 0 && s.count(num))
                return true;
            s.insert(num);
        }
        for(int num: arr){
            if(num != 0 && s.count(num * 2))
                return true;
        }
        return false;
    }
};