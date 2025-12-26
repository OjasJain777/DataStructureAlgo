class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int sr = 0;
        int ec = matrix[0].size()-1;
        while(sr<matrix.size() && ec>=0){
            if(matrix[sr][ec] == target){
                return true;
            }
            else if(matrix[sr][ec] <target){
                sr++;
            }
            else{
                ec--;
            }
        }
        return false;
    }
};