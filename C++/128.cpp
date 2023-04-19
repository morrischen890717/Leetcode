class Solution {
public:
    int longestConsecutive(vector<int>& nums) { // this method can reach O(n) time complexity
        /*
        If you have an array of size n and you want to build a heap from all 
        items at once, Floyd's algorithm can do it with O(n) complexity.
        If you have an empty priority queue to which you want to add n items, 
        one at a time, then the complexity is O(n * log(n)).
        Reference: https://stackoverflow.com/questions/44650882/time-complexity-of-a-priority-queue-in-c
        */
        priority_queue<int> pq(nums.begin(), nums.end());  // it takes O(n) time to build priority queue from vector nums
        int ans = 0;
        int cnt = 0;
        int num = INT_MAX;
        while(!pq.empty()){
            int top_num = pq.top();
            pq.pop();
            if(top_num == num - 1){
                cnt++;
                num--;
            }
            else if(top_num == num)
                continue;
            else{
                if(cnt > ans)
                    ans = cnt;
                cnt = 1;
                num = top_num;
            }
        }
        if(cnt > ans)
            ans = cnt;
        return ans;
    }
};