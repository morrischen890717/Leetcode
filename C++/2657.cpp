class Solution {
public:
    vector<int> findThePrefixCommonArray(vector<int>& A, vector<int>& B) {
        vector<int> ans;
        int n = A.size();
        unordered_map<int, int> cnt;
        int res = 0;
        for(int i = 0; i < n; i++){
            cnt[A[i]]++;
            cnt[B[i]]--;
            if(A[i] == B[i])
                res++;
            else{
                if(cnt[A[i]] == 0)
                    res++;
                if(cnt[B[i]] == 0)
                    res++;
            }
            ans.push_back(res);
        }
        return ans;
    }
};