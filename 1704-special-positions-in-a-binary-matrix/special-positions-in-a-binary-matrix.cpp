class Solution {
public:
    int numSpecial(vector<vector<int>>& mat) {
        int rs= mat.size();
        int cs = mat[0].size();
        vector<int> r(rs, 0);
        vector<int> c(cs,0);
        for(int i =0; i<rs;i++){
            for(int j =0; j<cs;j++){
                r[i] += mat[i][j];
                c[j] += mat[i][j];
            }
        }
        int ans=0;
        for(int i =0; i<rs;i++){
            for(int j =0; j<cs;j++){
                if(mat[i][j] ==1 && r[i] == 1 && c[j] == 1){
                    ans++;
                }
            }
        }
        return ans;
    }
};