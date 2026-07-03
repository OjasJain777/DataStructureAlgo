class Solution {
public:
    int longestCommonSubsequence(string s1, string s2) {
        vector<int> dp1(s2.size()+1, 0);
        for(int i = 1;i<=s1.size();i++){
            vector<int> dp2(s2.size()+1,0);
            for(int j = 1;j<=s2.size();j++){
                if(s1[i-1]==s2[j-1]){
                    dp2[j] = 1 + dp1[j-1];
                }
                else{
                    dp2[j] = 0 + max(dp2[j-1], dp1[j]);
                }
            }
            dp1=dp2;
        }
        return dp1.back();
    }
};