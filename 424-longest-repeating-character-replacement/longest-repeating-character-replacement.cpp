class Solution {
public:
    int characterReplacement(string s, int a) {
        int i = 0;
        int j =0;
        int ans = 0;
        vector<int> f(26,0);
        while(j<s.size()){
            int c = -1;
            f[s[j]-'A']++;
            for(int k = 0; k<26;k++){
                if(c==-1 || f[c] < f[k]){
                    c= k;
                }
                else{
                    continue;
                }
            }
            if(f[c] + a < (j-i+1)){
                f[s[i]-'A']--;
                i++;
                f[s[j]-'A']--;
            }
            else{
                ans = max(ans, j-i+1);
                j++;
            }
        }
        return ans;
    }
};