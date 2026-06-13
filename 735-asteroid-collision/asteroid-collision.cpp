class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        stack<int> s;
        for(int x: asteroids){
            if(x>0){
                s.push(x);
            }
            else if(x==0){
                if(s.size()>0 && s.top()>0){
                    s.pop();
                }
                s.push(x);
            }
            else{
                int l =1;
                while(s.size()!=0 && s.top()>=0){
                    if(s.top()>abs(x)){
                        l=0;
                        break;
                    }
                    else if(s.top()==abs(x)){
                        l=0;
                        s.pop();
                        break;
                    }
                    else{
                        l=1;
                        s.pop();
                    }
                }
                if(l==1){
                    s.push(x);
                }
            }
        }
        vector<int> ans(s.size());
        for(int i = s.size()-1;i>=0;i--){
            ans[i] = s.top();
            s.pop();
        }
        return ans;
    }
};