bool c(vector<vector<int>> &arr, int i, int j, int m){
    vector<int> dx = {-2,-2,2,2,-1,-1,1,1};
    vector<int> dy = {-1, 1, -1, 1, -2, 2, -2, 2};
    if(arr[i][j] == m){
        return 1;
    }
    int a = arr[i][j];
    for(int k =0; k<dx.size();k++){
        int in = i + dx[k];
        int jn = j + dy[k];
        if(in>=0 && in < arr.size() && jn>=0 && jn<arr[0].size()){
            if(arr[in][jn] == a+1){
                return c(arr, in, jn, m);
            }
        }
    }
    return 0;
};
class Solution {
public:
    bool checkValidGrid(vector<vector<int>>& grid) {
        int m = INT_MIN;
        if(grid[0][0] !=0){
            return 0;
        }
        for(int i =0; i<grid.size();i++){
            for(int j =0; j<grid[0].size();j++){
                m= max(m,grid[i][j]);
            }
        }
        return c(grid, 0,0, m);
    }
};