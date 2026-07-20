void l(vector<vector<int>>& grid, int m, int n) {
    int c = grid[m - 1][n - 1];
    int i = 0;
    int j = 0;
    int g = 0;
    while (g < m * n) {
        int t = grid[i][j];
        grid[i][j] = c;
        c = t;
        i += (j + 1) / n;
        j = (j + 1) % n;
        g++;
    }
}
class Solution {
public:
    vector<vector<int>> shiftGrid(vector<vector<int>>& grid, int k) {
        int m = grid.size();
        int n = grid[0].size();
        for(int i = 0; i<k;i++){
            l(grid,m,n);
        }
        return grid;
    }
};