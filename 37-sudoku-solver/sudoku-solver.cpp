bool t(vector<vector<char>> &board, unordered_map<int, unordered_set<char>> &b, unordered_map<int, unordered_set<char>> &c, unordered_map<int, unordered_set<char>> &r, int i, int j){
    if(i==9){
        return 1;
    }
    if(j==9){
        if(t(board, b, c,r, i+1,0)){
            return 1;
        }
    }
    if(board[i][j]<='9' && board[i][j]>='1'){
        if(t(board, b, c,r,i,j+1)){
            return 1;
        }
    }
    else{
        for(int k =1;k<=9;k++){
            if(b[(i/3)*3 +j/3].count(k+'0')==1 || c[j].count(k+'0')==1 || r[i].count(k+'0')==1){
                continue;
            }
            board[i][j]=k+'0';
            b[(i/3)*3+j/3].insert(k+'0');
            c[j].insert(k+'0');
            r[i].insert(k+'0');
            if(t(board, b,c,r,i,j+1)){
                return 1;
            }
            b[(i/3)*3+j/3].erase(k+'0');
            c[j].erase(k+'0');
            board[i][j] = '.';
            r[i].erase(k+'0');
        }
    }
    return 0;
}
class Solution {
public:
    void solveSudoku(vector<vector<char>>& board) {
        unordered_map<int, unordered_set<char>> b;
        unordered_map<int, unordered_set<char>> c;
        unordered_map<int, unordered_set<char>> r;
        for(int i =0;i<board.size();i++){
            for(int j =0;j<board[0].size();j++){
                if(board[i][j] >='1' && board[i][j] <='9'){
                    c[j].insert(board[i][j]);
                    r[i].insert(board[i][j]);
                    b[(i/3)*3 + j/3].insert(board[i][j]);
                }
            }
        }
        t(board, b,c,r,0,0);
    }
};