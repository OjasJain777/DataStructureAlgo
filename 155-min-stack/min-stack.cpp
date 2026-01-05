class MinStack {
public:
    vector<vector<int>> a;
    MinStack() {
        
    }
    
    void push(int val) {
        if(a.size()==0){
            a.push_back({val,val});
        }
        else{
            a.push_back({val, min(val, a[a.size()-1][1])});
        }
    }
    
    void pop() {
        a.pop_back();
    }
    
    int top() {
        return a[a.size()-1][0];
    }
    
    int getMin() {
        return a[a.size()-1][1];
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */