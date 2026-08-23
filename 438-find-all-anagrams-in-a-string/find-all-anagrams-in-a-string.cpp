class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        vector<int> c(26,0);
        for(auto &x : p){
            c[x-'a']++;
        }
        vector<int> f(26,0);
        int i =0;
        int j =0;
        vector<int> ans;
        while(j<s.size()){
            if(j<p.size()){
                f[s[j]-'a']++;
                j++;
            }
            else{
                f[s[j]-'a']++;
                j++;
                f[s[i]-'a']--;
                i++;
            }
            if(f==c){
                ans.push_back(i);
            }
        }
        return ans;
    }
};