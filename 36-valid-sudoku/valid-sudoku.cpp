class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        int i = 0;
        while(i<board.size()){
            unordered_map<char,int> fm;
            for(int j =0;j<board[0].size();j++){
                if(board[i][j] <= '9' && board[i][j] >='1'){
                    if(fm[board[i][j]]!=0){
                        return false;
                    }
                    else{
                        fm[board[i][j]]++;
                    }
                }
            }
            i++;
        }
        i = 0;
        while(i<board[0].size()){
            unordered_map<char,int> fm2;
            for(int j =0; j<board.size();j++){
                if(board[j][i]>='1' && board[j][i]<='9'){
                    if(fm2[board[j][i]]!=0){
                        return false;
                    }
                    else{
                        fm2[board[j][i]]++;
                    }
                }
            }
            i++;
        }
        i = 0;
        int j =0;
        while(i<board.size()){
            while(j<board[0].size()){
                unordered_map<char,int> v;
                for(int r = i;r<i+3;r++){
                    for(int c = j;c<j+3;c++){
                        if(board[r][c]<='9' && board[r][c]>='1'){
                            if(v[board[r][c]]!=0){
                                return false;
                            }
                            else{
                                v[board[r][c]]++;
                            }
                        }
                    }
                }
                j+=3;
            }
            j=0;
            i+=3;
        }
        return true;
    }
};