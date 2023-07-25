/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:
    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        string s = "";
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()){ // BFS
            int size = q.size();
            for(int i = 0; i < size; i++){
                if(q.front()){
                    s += to_string(q.front()->val);
                    q.push(q.front()->left);
                    q.push(q.front()->right);
                }
                else
                    s += ' '; // use ' ' to represents NULL
                q.pop();
                s += ',';
            }
        }
        return s;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        int len = data.length();
        vector<string> v;
        char *d = ",";
        // split data
        char *s = new char[len + 1];  // char array
        strcpy(s, data.c_str()); // convert data into char array so that strtok could be used
        char *p = strtok(s, d);
        while (p != NULL) {
            v.push_back(p);
            p = strtok(NULL, d);		   
        }
        if(v[0] == " ")
            return NULL;
        TreeNode *root = new TreeNode(stoi(v[0]));
        queue<TreeNode*> q;
        q.push(root);
        for(int i = 1; i < v.size(); i += 2){
            if(v[i] != " "){
                q.front()->left = new TreeNode(stoi(v[i]));
                q.push(q.front()->left);
            }
            if(v[i + 1] != " "){
                q.front()->right = new TreeNode(stoi(v[i + 1]));
                q.push(q.front()->right);
            }
            q.pop();
        }
        return root;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));