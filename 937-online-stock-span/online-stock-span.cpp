class StockSpanner {
public:
    vector<vector<int>> a;
    StockSpanner() {
        a = {};
    }
    
    int next(int price) {
        int i = a.size()-1;
        int c =1;
        while(i>=0){
            if(a[i][0] <= price){
                c += a[i][1];
                i -= a[i][1];
            }
            else{
                break;
            }
        }
        a.push_back({price, c});
        return c;
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */