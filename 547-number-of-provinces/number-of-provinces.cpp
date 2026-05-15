void t(vector<vector<int>> &m, vector<bool> &v, int i){
    v[i]=1;
    for(int j =0; j<m[0].size();j++){
        if(m[i][j]==1 && v[j]==0){
            t(m, v, j);
        }
    }
    return;
}
class Solution {
public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        int c =0;
        vector<bool> v(isConnected.size(),0);
        for(int k =0; k<v.size();k++){
            if(v[k]==0){
                t(isConnected, v, k);
                c++;
            }
        }
        return c;
    }
};