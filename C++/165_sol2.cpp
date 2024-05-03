class Solution {
public:
    int compareVersion(string version1, string version2) {
        int len1 = version1.length(), len2 = version2.length();
        vector<string> v1, v2;
        char delimiter = '.';
        int pos = version1.find(delimiter);
        while(pos != -1){
            v1.push_back(version1.substr(0, pos));
            version1 = version1.substr(pos + 1);
            pos = version1.find(delimiter);
        }
        v1.push_back(version1);
        pos = version2.find(delimiter);
        while(pos != -1){
            v2.push_back(version2.substr(0, pos));
            version2 = version2.substr(pos + 1);
            pos = version2.find(delimiter);
        }
        v2.push_back(version2);
        int n1 = v1.size(), n2 = v2.size();
        int i = 0, j = 0;
        while(i < n1 || j < n2){
            int num1 = i < n1 ? stoi(v1[i]) : 0, num2 = j < n2 ? stoi(v2[j]) : 0;
            if(num1 < num2)
                return -1;
            else if(num1 > num2)
                return 1;
            i++;
            j++;
        }
        return 0;
    }
};