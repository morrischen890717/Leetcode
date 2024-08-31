class Solution {
public:
    vector<int> relativeSortArray(vector<int>& arr1, vector<int>& arr2) {
        // using counting sort
        vector<int> cnt(1001, 0);
        for(int num: arr1){
            cnt[num]++;
        }
        int id = 0;
        for(int num: arr2){
            if(cnt[num]){
                for(int i = 0; i < cnt[num]; i++, id++){
                    arr1[id] = num;
                }
                cnt[num] = 0;
            }
        }
        for(int i = 0; i < cnt.size(); i++){
            if(cnt[i]){
                for(int j = 0; j < cnt[i]; j++, id++){
                    arr1[id] = i;
                }
            }
        }
        return arr1;
    }
};