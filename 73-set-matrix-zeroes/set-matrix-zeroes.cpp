class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        vector<vector<int>> a= matrix;
        for(int i =0; i<matrix.size();i++){
            for(int j=0; j<matrix[0].size();j++){
                if(matrix[i][j]==0){
                    for(int k =0;k<matrix.size();k++){
                        a[k][j] = 0;
                    }
                    for(int k =0;k<matrix[0].size();k++){
                        a[i][k] = 0;
                    }
                }
            }
        }
        matrix = a;
    }
};