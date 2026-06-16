class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        int e =0;
        int ans =0;
        int s =0;
        int l;
        unordered_map<int,int> m;
        while(e<fruits.size()){
            if(m.count(fruits[e]) == 1 || m.size()<2){
                m[fruits[e]] = e;
                l = fruits[e];
                ans = max(ans, e - s+1);
            }
            else{
                int d;
                for(auto y: m){
                    if(y.first == l){
                        continue;
                    }
                    s= y.second+1;
                    d = y.first;
                }
                m.erase(d);
                continue;
            }
            e++;
        }
        return ans;
    }
};