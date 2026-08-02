int f(int k, unordered_map<int,int> &p){
    if(p[k] == k){
        return k;
    }
    return p[k] = f(p[k],p);
}
void u(int a, int b, unordered_map<int,int> &p, unordered_map<int,int> &s){
    int ua = f(a,p);
    int ub = f(b,p);
    if(ua==ub){
        return;
    }
    if(s[ua] >= s[ub]){
        p[ub] = ua;
        s[ua] += s[ub];
    }
    else{
        p[ua] = ub;
        s[ub] += s[ua];
    }
}
class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_map<int,int> p;
        unordered_map<int,int> s;
        for(int x: nums){
            if(p.count(x)==0){
                p[x]=x;
                s[x]=1;
            }
            if(x != INT_MIN && p.count(x-1) != 0){
                u(x-1, x, p,s);
            }
            if(x!=INT_MAX && p.count(x+1) != 0){
                u(x+1,x, p,s);
            }
        }
        int m = 0;
        for(auto &y: s){
            m = max(m, y.second);
        }
        return m;
    }
};