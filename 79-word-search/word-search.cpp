void t(int i, int j, string a, vector<vector<char>> &b, int l, int &ans){
    int c =0;
    if(l==a.size()){
        ans += 1;
        return;
    }
    if(i>0 && b[i-1][j] == a[l]){
        int g = b[i][j];
        b[i][j] = '%';
        t(i-1, j, a, b, l+1, ans);
        b[i][j] = g;

        c=1;
    }
    if(i<b.size()-1 && b[i+1][j] == a[l]){
        int g = b[i][j];
        b[i][j] = '%';
        t(i+1, j, a, b, l+1, ans);
        b[i][j] = g;
        c=1;
    }
    if(j>0 && b[i][j-1] == a[l]){
        int g = b[i][j];
        b[i][j] = '%';
        t(i, j-1, a, b, l+1, ans);
        b[i][j] = g;
        c=1;
    }
    if(j<b[0].size()-1 && b[i][j+1] == a[l]){
        int g = b[i][j];
        b[i][j] = '%';
        t(i, j+1, a, b, l+1, ans);
        b[i][j] = g;
        c=1;
    }
    if(c==0){
        ans += 0;
    }
}
class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
        int ans = 0;
        for(int i =0; i<board.size();i++){
            for(int j =0; j<board[0].size();j++){
                if(board[i][j] == word[0]){
                    t(i, j, word, board, 1, ans);
                }
            }
        }
        return ans;
    }
};