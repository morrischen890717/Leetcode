class Solution {
public:
    int compareVersion(string version1, string version2) {
        char *str1 = new char[version1.length() + 1];
        char *str2 = new char[version2.length() + 1];
        strcpy(str1, version1.c_str());
        strcpy(str2, version2.c_str());
        char *d = ".";
        char *p1, *p2;
        char *saveptr1 = NULL;
        char *saveptr2 = NULL;
        int int1, int2;
        p1 = strtok_r(str1, d, &saveptr1);
        p2 = strtok_r(str2, d, &saveptr2);
        while(p1 != NULL || p2 != NULL){
            int1 = (p1 != NULL ? stoi(p1) : 0);
            int2 = (p2 != NULL ? stoi(p2) : 0);
            if(int1 < int2)
                return -1;
            else if(int1 > int2)
                return 1;
            
            p1 = strtok_r(saveptr1, d, &saveptr1); 
            p2 = strtok_r(saveptr2, d, &saveptr2);
            /*
            char *strtok_r(char *str, const char *delim, char **saveptr);
            saveptr1 represent the address which start to be spilt, and &saveptr1 represent the address which stores the address of the pointer saveptr1
            check out http://naeilproj.blogspot.com/2015/10/linux-c-strtokstrtokr.html
            */
        }
        return 0;   
    }
};