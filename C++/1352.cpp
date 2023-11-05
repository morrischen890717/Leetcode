class ProductOfNumbers {
public:
    vector<int> prefix;
    ProductOfNumbers() {
        prefix = {1};
    }
    
    void add(int num) {
        if(num == 0)
            prefix = {1};
        else
            prefix.push_back(prefix.back() * num);
        return;
    }
    
    int getProduct(int k) {
        // using prefix sum
        // time complexity: O(1)
        // reference: https://leetcode.com/problems/product-of-the-last-k-numbers/solutions/510260/java-c-python-prefix-product/
        return k >= prefix.size() ? 0 : prefix.back() / prefix[prefix.size() - k - 1];
    }
};

/**
 * Your ProductOfNumbers object will be instantiated and called as such:
 * ProductOfNumbers* obj = new ProductOfNumbers();
 * obj->add(num);
 * int param_2 = obj->getProduct(k);
 */