class Solution {
public:
    vector<vector<int>> getSkyline(vector<vector<int>>& buildings) {
        /*
        using multiset(we do not use set because it might have deplicate height, 
        and we do not use priority_queue because we need to erase a element which in not the top element in pq)
        time complexity: O(NlogN)
        reference: https://leetcode.com/problems/the-skyline-problem/solutions/2094329/c-easiest-explanation-ever-guaranteed-beginner-friendly-detailed-o-nlogn/?envType=featured-list&envId=top-interview-questions
        */
        vector<vector<int>> ans;
        //priority_queue<pair<int, int>, vector<pair<int, int>>> pq;
        multiset<int> pq; // stores height (using multiset instead of set because height might be deplicate)
        vector<pair<int, int>> points;
        for(vector<int>& building: buildings){
            points.push_back({building[0], -building[2]}); // let height be negative to make sorting easier
            points.push_back({building[1], building[2]});
        }
        sort(points.begin(), points.end()); // overall time: O(NlogN)
        int prevMax = -1;
        for(pair<int, int>& p: points){ // overall time: O(NlogN)
            int pos = p.first, h = p.second;
            if(h < 0)
                pq.insert(-h);
            else
                pq.erase(pq.find(h)); // only erase one element, find() costs O(log(pq.size())) time, erase costsO(1) time
            int curMax = pq.empty() ? 0 : *pq.rbegin(); // rbegin() will get the last element, which is the largest element in multiset
            if(curMax != prevMax){
                prevMax = curMax;
                ans.push_back({pos, prevMax});
            }
        }
        return ans;
    }
};