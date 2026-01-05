class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        if(strs.size()==0){
            return {{}};
        }
        unordered_map<string, vector<string>> a;
        for(int i =0;i<strs.size();i++){
            map<char,int> b;
            for(int j = 0; j<strs[i].size();j++){
                b[strs[i][j]] ++;
            }
            string c="";
            for(auto y: b){
                for(int k =0;k<y.second;k++){
                    c+=y.first;
                }
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