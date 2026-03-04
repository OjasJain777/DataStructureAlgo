class Solution {
public:
    int numSpecial(vector<vector<int>>& mat) {
        unordered_map<int, int> r;
        unordered_map<int, int> c;
        for(int i =0; i<mat.size();i++){
            for(int j =0; j< mat[0].size();j++){
                r[i] += mat[i][j];
                c[j] += mat[i][j];
            }
        }
        int ans=0;
        for(int i = 0; i<mat.size();i++){
            for(int j =0;j<mat[0].size();j++){
                if(mat[i][j] == 1 && r[i]==1 && c[j]==1){
                    ans++;
                }
            }
        }
        return ans;
    }
};