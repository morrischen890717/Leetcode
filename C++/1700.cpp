class Solution {
public:
    int countStudents(vector<int>& students, vector<int>& sandwiches) {
        // time complexity: O(N), space complexity: O(1)
        int cnt_0 = 0, cnt_1 = 0;
        for(int student: students){
            if(student)
                cnt_1++;
            else
                cnt_0++;
        }
        for(int sandwich: sandwiches){
            if(sandwich){
                if(cnt_1)
                    cnt_1--;
                else
                    return cnt_0;
            }
            else{
                if(cnt_0)
                    cnt_0--;
                else
                    return cnt_1;
            }
        }
        return 0;
    }
};