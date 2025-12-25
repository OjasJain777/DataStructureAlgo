class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        vector<vector<int>> a;
        for(int i =0; i<matrix.size();i++){
            for(int j =0; j<matrix[0].size();j++){
                if(matrix[i][j]==0){
                    a.push_back({i,j});
                }
            }
        }
        for(int k =0; k<a.size();k++){
            for(int j=0;j<matrix[0].size();j++){
                matrix[a[k][0]][j] = 0;
            }
            for(int i =0; i<matrix.size();i++){
                matrix[i][a[k][1]] = 0;
            }
        }
    }
};