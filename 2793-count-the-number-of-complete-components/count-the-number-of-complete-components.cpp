vector<int> p;
vector<int> sz;
vector<int> e;

int f(int x){
    if(x == p[x]){
        return x;
    }
    return p[x] = f(p[x]);
}

void u(int a, int b){
    int ua = f(a);
    int ub = f(b);

    if(ua == ub){
        e[ua]++;
        return;
    }

    if(sz[ua] > sz[ub]){
        p[ub] = ua;
        sz[ua] += sz[ub];
        e[ua] += e[ub];
        e[ua]++;
    }
    else{
        p[ua] = ub;
        sz[ub] += sz[ua];
        e[ub] += e[ua];
        e[ub]++;
    }
}

class Solution {
public:
    int countCompleteComponents(int n, vector<vector<int>>& edges) {
        p.clear();
        sz.clear();
        e.clear();

        for(int i = 0; i < n; i++){
            p.push_back(i);
            sz.push_back(1);
            e.push_back(0);
        }

        for(auto &x : edges){
            u(x[0], x[1]);
        }
        int ans =0;
        for(int i = 0; i<n;i++){
            if(p[i]==i){
                int b = (sz[i])*(sz[i]-1);
                b /= 2;
                if(b == e[i]){
                    ans++;
                }
            }
        }
        
        return ans;
    }
};