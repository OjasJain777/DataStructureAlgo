class StockSpanner {
public:
    stack<pair<int,int>> s;
    int i =0;
    StockSpanner() {
        
    }
    
    int next(int price) {
        int a;
        while(s.size()!=0 && s.top().second <= price){
            s.pop();
        }
        if(s.size()==0){
            a = i+1;
        }
        else{
            a = i - (s.top().first);
        }
        s.push({i, price});
        i++;
        return a;
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */