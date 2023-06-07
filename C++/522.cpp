class Solution {
public:
    static bool cmp(string a, string b){
        return a.length() > b.length();
    }
    bool isSubsequence(string a, string b){
        int len1 = a.length(), len2 = b.length();
        int ptr1 = 0, ptr2 = 0;
        while(ptr1 < len1 && ptr2 < len2){
            if(a[ptr1] == b[ptr2])
                ptr2++;
            ptr1++;
        }
        return ptr2 == len2;
    }
    int findLUSlength(vector<string>& strs) {
        int n = strs.size();
        sort(strs.begin(), strs.end(), cmp);
        for(int i = 0; i < n; i++){
            int lus = -1;
            for(int j = 0; j < n; j++){
                if(i == j)
                    continue;
                if(isSubsequence(strs[j], strs[i])){
                    lus = -1;
                    break;
                }
                else
                    lus = strs[i].length();
            }
            if(lus != -1)
                return lus;
        }
        return -1;
    }
};