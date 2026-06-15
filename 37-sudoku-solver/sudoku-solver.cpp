class Solution {
public:

    int row[9] = {};
    int col[9] = {};
    int box[9] = {};

    bool solve(vector<vector<char>>& board, int i, int j) {

        if(i == 9)
            return true;

        if(j == 9)
            return solve(board, i + 1, 0);

        if(board[i][j] != '.')
            return solve(board, i, j + 1);

        int b = (i/3)*3 + (j/3);

        for(int d = 1; d <= 9; d++) {

            int bit = 1 << (d - 1);

            if((row[i] & bit) ||
               (col[j] & bit) ||
               (box[b] & bit))
                continue;

            board[i][j] = d + '0';

            row[i] |= bit;
            col[j] |= bit;
            box[b] |= bit;

            if(solve(board, i, j + 1))
                return true;

            board[i][j] = '.';

            row[i] ^= bit;
            col[j] ^= bit;
            box[b] ^= bit;
        }

        return false;
    }

    void solveSudoku(vector<vector<char>>& board) {

        for(int i = 0; i < 9; i++) {

            for(int j = 0; j < 9; j++) {

                if(board[i][j] == '.')
                    continue;

                int d = board[i][j] - '0';
                int bit = 1 << (d - 1);

                row[i] |= bit;
                col[j] |= bit;
                box[(i/3)*3 + (j/3)] |= bit;
            }
        }

        solve(board, 0, 0);
    }
};