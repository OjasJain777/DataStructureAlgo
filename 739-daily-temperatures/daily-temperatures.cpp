class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& t) {
        vector<int> ans(t.size());
        int k = t.size()-1;
        stack<int> s;
        for(int j = t.size()-1;j>=0;j--){
            while(!s.empty() && t[s.top()] <= t[j]){
                s.pop();
            }
            if(s.empty()){
                ans[k] = 0;
            }
            else{
                ans[k] = s.top() - j;;
            }
            s.push(j);
            k--;
        }
        return ans;
    }
};