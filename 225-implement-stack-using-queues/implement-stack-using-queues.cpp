class MyStack {
public:
    queue<int> q1;
    MyStack() {
        q1={};
    }
    
    void push(int x) {
        q1.push(x);
    }
    
    int pop() {
        if(q1.size()==0){
            return -1;
        }
        for(int i =0;i<q1.size()-1;i++){
            int a = q1.front();
            q1.pop();
            q1.push(a);
        }
        auto a = q1.front();
        q1.pop();
        return a;        
    }
    
    int top() {
        if(q1.size()==0){
            return -1;
        }
        for(int i =0;i<q1.size()-1;i++){
            int a = q1.front();
            q1.pop();
            q1.push(a);
        }
        auto a = q1.front();
        q1.pop();
        q1.push(a);
        return a;                
    }
    
    bool empty() {
        if(q1.size()==0){
            return 1;
        }
        return 0;
    }
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */