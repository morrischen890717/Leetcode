class NumberContainers {
private:
    unordered_map<int, int> index2num;
    unordered_map<int, priority_queue<int, vector<int>, greater<int>>> num2index;
public:
    NumberContainers() {
        
    }
    
    void change(int index, int number) {
        index2num[index] = number;
        num2index[number].push(index);
        return;
    }
    
    int find(int number) {
        if(!num2index.count(number))
            return -1;
        while(!num2index[number].empty()){
            int cur = num2index[number].top();
            if(index2num[cur] == number)
                return cur;
            num2index[number].pop();
        }
        return -1;
    }
};

/**
 * Your NumberContainers object will be instantiated and called as such:
 * NumberContainers* obj = new NumberContainers();
 * obj->change(index,number);
 * int param_2 = obj->find(number);
 */