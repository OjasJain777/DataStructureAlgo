vector<int> dx = {1,-1,0,0};
vector<int> dy = {0,0,1,-1};
bool t(int i, int j, vector<vector<char>> &board, string &a, string &word){
    if(a.size()==word.size()){
        return 1;
    }
    bool r = 0;
    for(int k =0;k<4;k++){
        if(i+dx[k]>=0 && i+dx[k]<board.size() && j+dy[k]>=0 && j+dy[k]<board[0].size() && board[i+dx[k]][j+dy[k]] == word[a.size()]){
            a.push_back(word[a.size()]);
            char h = board[i+dx[k]][j+dy[k]];
            board[i+dx[k]][j+dy[k]] = '1';
            r = r || t(i+dx[k], j+dy[k], board, a, word);
            board[i+dx[k]][j+dy[k]] = h;
            a.pop_back();
        }
    }
    return r;
}
class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
        string a;
        bool ans = 0;
        for(int i = 0;i<board.size();i++){
            for(int j = 0;j<board[0].size();j++){
                if(board[i][j] == word[0]){
                    a.push_back(word[0]);
                    board[i][j]='1';
                    ans = ans || t(i,j, board, a, word);
                    board[i][j]=word[0];
                    a.pop_back();
                }
            }
        }
        return ans;
    }
};