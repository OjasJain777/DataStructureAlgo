class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        vector<int> c;
        for(int j =0; j<matrix[0].size();j++){
            if(target >= matrix[0][j] && target <= matrix[matrix.size()-1][j]){
                c.push_back(j);
            }
        }
        vector<int> r;
        for(int i =0;i<matrix.size();i++){
            if(target>=matrix[i][0] && target<= matrix[i][matrix[0].size()-1]){
                r.push_back(i);
            }
        }
        for(int i: r){
            for(int j:c){
                if(matrix[i][j]==target){
                    return true;
                }
            }
        }
        return false;
    }
};