class CombinationIterator {
private:
    vector<int> ptr;
    string characters;
public:
    CombinationIterator(string characters, int combinationLength) {
        this->characters = characters;
        ptr = vector<int> (combinationLength);
        for(int i = 0; i < combinationLength; i++){
            ptr[i] = i;
        }
        ptr[combinationLength - 1]--;
    }

    string next() {
        for(int i = ptr.size() - 1; i >= 0; i--){
            int pos = ptr[i], end_pos = characters.length() - (ptr.size() - i);
            if(pos < end_pos){
                ptr[i]++;
                for(int j = i + 1; j < ptr.size(); j++){
                    ptr[j] = ptr[j - 1] + 1;
                }
                string res = "";
                for(int pos: ptr){
                    res += characters[pos];
                }
                return res;
            }
        }
        return "";
    }
    
    bool hasNext() {
        for(int i = 0; i < ptr.size(); i++){
            if(ptr[i] != characters.length() - (ptr.size() - i))
                return true;
        }
        return false;
    }
};

/**
 * Your CombinationIterator object will be instantiated and called as such:
 * CombinationIterator* obj = new CombinationIterator(characters, combinationLength);
 * string param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */