class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        if(strs.size()==0){
            return {{}};
        }
        unordered_map<string, vector<string>> a;
        for(int i =0;i<strs.size();i++){
            vector<char> b;
            for(int j = 0; j<strs[i].size();j++){
                b.push_back(strs[i][j]);
            }
            sort(b.begin(),b.end());
            string c = "";
            for(int k=0;k<b.size();k++){
                c+=b[k];
            }
            a[c].push_back(strs[i]);
        }
        vector<vector<string>> ans;
        for(auto y: a){
            ans.push_back(y.second);
        }
        return ans;
    }
};