class Solution {
public:
    int count_people(long long people){
        int cnt = 0;
        while(people){
            if(people & 1)
                cnt++;
            people >>= 1;
        }
        return cnt;
    }
    long long dfs(vector<string>& req_skills, vector<int>& people_skills, vector<vector<long long>>& dp, int req, int i){
        // req stands for the remaining requested skills, i stands for the current person
        if(req == 0)
            return (long long)1 << (i - 1); // previous i
        if(i >= people_skills.size())
            return -1; // -1 means that it is impossible to get all the requested skills
        if(dp[i][req] != -2)
            return dp[i][req];
        // Knapsack 0/1 Problem
        long long not_take = dfs(req_skills, people_skills, dp, req, i + 1);
        long long take = ((long long)1 << i) | dfs(req_skills, people_skills, dp, req & ~people_skills[i], i + 1);
        // if take == -1, then not_take must be -1
        if(not_take == -1)
            dp[i][req] = take;
        else 
            dp[i][req] = (count_people(take) < count_people(not_take) ? take : not_take);
        return dp[i][req];
    }
    vector<int> smallestSufficientTeam(vector<string>& req_skills, vector<vector<string>>& people) {
        int skills_num = req_skills.size();
        int people_num = people.size();
        unordered_map<string, int> m;
        // dp[i][req] stands for the people with the smallest size that could satisfy req from person i to the end
        vector<vector<long long>> dp(people_num, vector<long long> (1 << skills_num, -2));
        vector<int> people_skills(people_num, -1);
        for(int i = 0; i < skills_num; i++){
            m[req_skills[i]] = i;
        }
        for(int i = 0; i < people_num; i++){
            int skills = 0;
            for(int j = 0; j < people[i].size(); j++){
                if(m.count(people[i][j]) > 0)
                    skills |= (1 << m[people[i][j]]);
            }
            people_skills[i] = skills;
        }
        long long res = dfs(req_skills, people_skills, dp, (1 << skills_num) - 1, 0);
        vector<int> ans;
        int id = 0;
        while(res){
            if(res & 1)
                ans.push_back(id);
            id++;
            res >>= 1;
        }
        return ans;
    }
};