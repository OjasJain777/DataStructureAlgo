class Solution {
public:
    void solve(vector<vector<char>>& board) {
        queue<pair<int, int>> q;
        for(int k =0; k<board.size();k++){
            if(board[k][0]=='O'){
                board[k][0] = '#';
                q.push({k, 0});
            }
            if(board[k][board[0].size()-1]=='O'){
                q.push({k, board[0].size()-1});
                board[k][board[0].size()-1] = '#';
            }
        }
        for(int k =0; k<board[0].size();k++){
            if(board[0][k]=='O'){
                q.push({0, k});
                board[0][k] = '#';
            }
            if(board[board.size()-1][k]=='O'){
                q.push({board.size()-1, k});
                board[board.size()-1][k]= '#';
            }
        }
        while(q.size()>0){
            auto y = q.front();
            int i = y.first;
            int j = y.second;
            q.pop();
            vector<int> dx = {1, -1, 0, 0};
            vector<int> dy = {0, 0, 1, -1};
            for(int k =0; k<dx.size();k++){
                if(i+dx[k]>=0 && i+dx[k]< board.size() && j+dy[k]>=0 && j+dy[k] < board[0].size() && board[i+dx[k]][j+dy[k]]=='O'){
                    q.push({i+dx[k], j+dy[k]});
                    board[i+dx[k]][j+dy[k]] = '#';
                }
            }
        }
        for(int r =0; r<board.size();r++){
            for(int c =0; c<board[0].size();c++){
                if(board[r][c]=='O'){
                    q.push({r,c});
                    board[r][c]='X';
                }
            }
        }
        while(q.size()>0){
            auto y = q.front();
            int i = y.first;
            int j = y.second;
            vector<int> dx = {1, -1, 0, 0};
            vector<int> dy  {0, 0, 1, -1};
            q.pop();
            for(int k =0; k<dx.size();k++){
                if(i+dx[k]>=0 && i+dx[k] < board.size() && j+dy[k] >=0 && j+dy[k] < board[0].size() && board[i+dx[k]][j+dy[k]]=='O'){
                    q.push({i+dx[k], j+dy[k]});
                    board[i+dx[k]][j+dy[k]] = 'X';
                }
            }
        }
        for(int r =0; r< board.size(); r++){
            for(int c= 0; c<board[0].size(); c++){
                if(board[r][c] == '#'){
                    board[r][c] = 'O';
                }
            }
        }
    }
};