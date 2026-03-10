class Solution {
public:
    int beautySum(string s) {
        int ans =0;
        for(int i =0;i<s.size();i++){
            int mi = 1;
            int ma =1;
            unordered_map<char, int> f;
            unordered_map<int, int> g;
            f[s[i]] ++;
            g[f[s[i]]]++;
            for(int j = i+1; j<s.size();j++){

                int p = f[s[j]];
                f[s[j]]++;
                if(g[p]!=0){
                    g[p]--;
                }
                g[f[s[j]]]++;
                ma = max(ma, f[s[j]]);
                while(g[mi]==0){
                    mi++;
                }
                mi = min(mi, f[s[j]]);
                ans += (ma-mi);
            }
        }
        return ans;
    }
};