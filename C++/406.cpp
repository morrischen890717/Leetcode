class Solution {
public:
    static bool cmp(vector<int>& a, vector<int>& b){
        if(a[0] != b[0])
            return a[0] > b[0]; // descending for h
        return a[1] < b[1]; // ascending for k
    }
    vector<vector<int>> reconstructQueue(vector<vector<int>>& people) {
        /*
        reference: https://leetcode.com/problems/queue-reconstruction-by-height/solutions/89345/easy-concept-with-python-c-java-solution/
        */
        sort(people.begin(), people.end(), cmp);
        vector<vector<int>> ans;
        for(int i = 0; i < people.size(); i++){
            ans.insert(ans.begin() + people[i][1], people[i]);
        }
        return ans;
    }
};