class Solution {
public:
    vector<string> fullJustify(vector<string>& words, int maxWidth) {
        vector<string> ans;
        int n = words.size();
        int len = 0, wordCnt = 0;
        queue<string> q;
        int start = 0;
        for(int i = 0; i < n; i++){
            if(len + wordCnt + words[i].length() > maxWidth){
                string s = words[start];
                start++;
                wordCnt--;
                int totalSpace = maxWidth - len;
                for(; start < i; start++){
                    int spaceCnt = totalSpace / wordCnt + (totalSpace % wordCnt ? 1 : 0);
                    for(int j = 0; j < spaceCnt; j++){
                        s += ' ';
                    }
                    s += words[start];
                    totalSpace -= spaceCnt;
                    wordCnt--;
                }
                while(totalSpace){
                    s += ' ';
                    totalSpace--;
                }
                ans.push_back(s);
                wordCnt = 1;
                len = words[i].length();
            }
            else{
                len += words[i].length();
                wordCnt++;
            }
        }
        string s;
        for(; start < n; start++){
            s += words[start];
            if(start != n - 1)
                s += ' ';
        }
        while(s.length() < maxWidth){
            s += ' ';
        }
        ans.push_back(s);
        return ans;
    }
};