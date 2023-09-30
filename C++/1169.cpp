class Solution {
private:
    class Transaction {
    public: 
        string name, city;
        int time, amount;
        Transaction (string name, int time, int amount, string city){
            this->name = name;
            this->time = time;
            this->amount = amount;
            this->city = city;
        }
    };
public:
    vector<string> invalidTransactions(vector<string>& transactions) {
        // using self-defined class
        // time complexity: O(N^2)
        int n = transactions.size();
        vector<string> ans;
        vector<Transaction*> v;
        char d = ',';
        for(int i = 0; i < n; i++){
            string transaction = transactions[i];
            vector<string> res;
            string name = "";
            string::size_type begin, end;
            begin = 0;
            end = transaction.find(d);
            while(end != string::npos){
                if(end - begin != 0)
                    res.push_back(transaction.substr(begin, end - begin));
                begin = end + 1;
                end = transaction.find(d, begin);
            }
            if(begin != transaction.length())
                res.push_back(transaction.substr(begin));
            Transaction *t = new Transaction(res[0], stoi(res[1]), stoi(res[2]), res[3]);
            v.push_back(t);
        }
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                if(v[i]->amount > 1000 || (v[i]->name == v[j]->name && abs(v[i]->time - v[j]->time) <= 60 && v[i]->city != v[j]->city)){
                    ans.push_back(transactions[i]);
                    break;
                }
            }
        }
        return ans;
    }
};