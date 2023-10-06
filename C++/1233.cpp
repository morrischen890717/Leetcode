class Solution {
private:
    class Trie {
    public:
        bool isFolder;
        unordered_map<string, Trie*> child;
        Trie(){
            isFolder = false;
        }
    };
public:
    vector<string> removeSubfolders(vector<string>& folder) {
        // using Trie and sort()
        vector<string> ans;
        int n = folder.size();
        sort(folder.begin(), folder.end());
        Trie *root = new Trie();
        for(string& f: folder){
            Trie *cur = root;
            string s = "";
            for(char c: f){
                if(c != '/')
                    s += c;
                else{
                    if(cur->child.count(s) == 0)
                        cur->child[s] = new Trie();
                    cur = cur->child[s];
                    if(cur->isFolder)
                        break;
                }
            }
            if(!cur->isFolder){ // if not break in the aboved code
                cur->child[s] = new Trie();
                cur->child[s]->isFolder = true;
                ans.push_back(f);
            }
        }
        return ans;
    }
};