class Solution {
public:
    int findRadius(vector<int>& houses, vector<int>& heaters) {
        /*
        time complexity: O(NlogN)
        reference: https://leetcode.com/problems/heaters/solutions/3355888/simple-and-easy-to-understand-c-solution-tc-o-n-sc-o-n/
        */
        int n1 = houses.size(), n2 = heaters.size();
        sort(houses.begin(), houses.end());
        sort(heaters.begin(), heaters.end());
        vector<int> d(n1, INT_MAX);
        int i = 0, j = 0;
        while(i < n1 && j < n2){
            if(houses[i] >= heaters[j])
                j++;
            else{
                d[i] = heaters[j] - houses[i];
                i++;
            }
        }
        i = n1- 1, j = n2 - 1;
        while(i >= 0 && j >= 0){
            if(houses[i] < heaters[j])
                j--;
            else{
                d[i] = min(d[i], houses[i] - heaters[j]);
                i--;
            }
        }
        return *max_element(d.begin(), d.end());
    }
};