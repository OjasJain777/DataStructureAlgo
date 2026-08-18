class Solution {
public:
    int characterReplacement(string s, int k) {
        vector<int> f(26,0);
        int l  = 0;
        int ans = 0;
        int r = 0;
        while(r<s.size()){
            int m = 0;
            f[s[r]-'A']++;
            for(int i = 0 ; i<26;i++){
                if(f[m] < f[i]){
                    m=i;
                }
            }
            int d = r-l+1-f[m];
            if(d>k){
                f[s[l]-'A']--;
                f[s[r]-'A']--;
                l++;
            }
            else{
                r++;
                ans = max(ans, r-l);
            }
        }
        return ans;
    }
};