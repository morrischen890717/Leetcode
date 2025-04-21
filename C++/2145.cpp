class Solution {
public:
    int numberOfArrays(vector<int>& differences, int lower, int upper) {
        /*
        reference:
        https://leetcode.com/problems/count-the-hidden-sequences/solutions/1709755/java-c-python-straight-forward-solution-with-explantion/?envType=daily-question&envId=2025-04-21
        https://imgur.com/a/AMsAK4P
        */
        long long d = 0, max_d = 0, min_d = 0;
        for(int diff: differences){
            d += diff;
            if(d > max_d)
                max_d = d;
            if(d < min_d)
                min_d = d;
        }
        int res = upper - lower - (max_d - min_d) + 1;
        return max(0, res);
    }
};