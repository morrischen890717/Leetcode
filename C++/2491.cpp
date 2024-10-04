class Solution {
public:
    long long dividePlayers(vector<int>& skill) {
        long long ans = 0;
        int n = skill.size();
        sort(skill.begin(), skill.end());
        int target = skill[0] + skill.back();
        for(int i = 0; i < n / 2; i++){
            if(skill[i] + skill[n - 1 - i] != target)
                return -1;
            ans += skill[i] * skill[n - 1 - i];
        }
        return ans;
    }
};