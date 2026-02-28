void t(vector<vector<int>> &m, vector<string> &ans, int i, int j, string s){
    if(i==j && j==m.size()-1){
        ans.push_back(s);
        return;
    }
    m[i][j]=0;
    if(i+1>=0 && i+1 < m.size() && m[i+1][j] == 1){
        t(m, ans, i+1, j, s+'D');
    }
    if(j-1>=0 && j-1<m[0].size() && m[i][j-1]==1){
        t(m, ans, i, j-1, s+'L');
    }
    if(j+1>=0 && j+1 < m[0].size() && m[i][j+1]==1){
        t(m, ans, i, j+1, s+'R');
    }
    if(i-1>=0 && i-1<m.size() && m[i-1][j]==1){
        t(m, ans, i-1, j, s+'U');
    }
    m[i][j]=1;
}
class Solution {
  public:
    vector<string> ratInMaze(vector<vector<int>>& maze) {
        vector<string> ans;
        string s = "";
        t(maze, ans, 0,0,s);
        return ans;
    }
};