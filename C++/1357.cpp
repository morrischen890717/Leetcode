class Cashier {
public:
    unordered_map<int, int> price;
    int n, discount, cnt;
    Cashier(int n, int discount, vector<int>& products, vector<int>& prices) {
        for(int i = 0; i < products.size(); i++){
            price[products[i]] = prices[i];
        }
        this->n = n;
        this->discount = discount;
        cnt = 0;
    }
    
    double getBill(vector<int> product, vector<int> amount) {
        // using unordered_map
        double sum = 0.0;
        for(int i = 0; i < product.size(); i++){
            sum += price[product[i]] * amount[i];
        }
        cnt++;
        if(cnt == n){
            sum *= ((100.0 - discount) / 100);
            cnt = 0;
        }
        return sum;
    }
};

/**
 * Your Cashier object will be instantiated and called as such:
 * Cashier* obj = new Cashier(n, discount, products, prices);
 * double param_1 = obj->getBill(product,amount);
 */