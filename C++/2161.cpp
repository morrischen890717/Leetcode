class Solution {
public:
    vector<int> pivotArray(vector<int>& nums, int pivot) {
        int cnt = 0;
        queue<int> less, greater;
        for(int num: nums){
            if(num == pivot)
                cnt++;
            else if(num < pivot)
                less.push(num);
            else
                greater.push(num);
        }
        for(int i = 0; i < nums.size(); i++){
            if(!less.empty()){
                nums[i] = less.front();
                less.pop();
            }
            else if(cnt > 0){
                nums[i] = pivot;
                cnt--;
            }
            else{
                nums[i] = greater.front();
                greater.pop();
            }
        }
        return nums;
    }
};