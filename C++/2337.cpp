class Solution {
public:
    bool canChange(string start, string target) {
        // using two-pointers
        // time complexity: O(N), space complexity: O(1)
        // reference: https://leetcode.com/problems/move-pieces-to-obtain-a-string/solutions/2261229/faster-than-100-00-o-n-java-and-c/?envType=daily-question&envId=2024-12-05
        int len = start.length();
        int i = 0, j = 0;
        while(i < len || j < len){
            while(i < len && start[i] == '_'){
                i++;
            }
            while(j < len && target[j] == '_'){
                j++;
            }
            if(i == len || j == len)
                return i == len && j == len;
            if(start[i] != target[j])
                return false;
            if(start[i] == 'L'){
                if(i < j)
                    return false;
            }
            else if(j < i)
                return false;
            i++;
            j++;
        }
        return true;
    }
};