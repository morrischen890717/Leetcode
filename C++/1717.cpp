class Solution {
public:
    int remove(string& s, string request, int p){
        int point = 0;
        int i = 0;
        for(int j = 0; j < s.length(); j++){
            s[i] = s[j];
            if(i >= 1 && s[i - 1] == request[0] && s[i] == request[1]){
                i -= 2;
                point += p;
            }
            i++;
        }
        s = s.substr(0, i);
        return point;
    }
    int maximumGain(string s, int x, int y) {
        // using Greedy
        // time complexity: O(N), space complexity: O(1)
        // reference: https://leetcode.com/problems/maximum-score-from-removing-substrings/solutions/1009028/c-greedy-o-n-time-o-1-space/?envType=daily-question&envId=2024-07-12
        string a = "ab", b = "ba";
        if(x < y){
            swap(a, b);
            swap(x, y);
        }
        return remove(s, a, x) + remove(s, b, y);
    }
};