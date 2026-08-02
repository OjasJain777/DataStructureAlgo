class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        vector<unordered_set<char>> row(9);
        vector<unordered_set<char>> col(9);
        vector<vector<unordered_set<char>>> box(3, vector<unordered_set<char>>(3));

        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++) {
                if (board[i][j] == '.') continue;

                char x = board[i][j];

                if (row[i].count(x) || col[j].count(x) || box[i / 3][j / 3].count(x))
                    return false;

                row[i].insert(x);
                col[j].insert(x);
                box[i / 3][j / 3].insert(x);
            }
        }

        return true;
    }
};