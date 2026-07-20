class Solution {
public:
    vector<vector<char>> rotateTheBox(vector<vector<char>>& bg) {
        int m = bg.size();
        int n = bg[0].size();
        for(int i= 0;i<m;i++){
            int l =-1;
            for(int j = n-1;j>=0;j--){
                if(bg[i][j] == '*'){
                    l=-1;
                }
                else if(bg[i][j] == '#'){
                    if(l==-1){
                        continue;
                    }
                    bg[i][j]= '.';
                    bg[i][l] = '#';
                    while(l>=0 && bg[i][l] != '.'){
                        l--;
                    }
                }
                else{
                    if(l==-1){
                        l=j;
                    }
                }
            }
        }
        vector<vector<char>> ans;
        for(int j = 0; j<n;j++){
            vector<char> a;
            for(int i = m-1;i>=0;i--){
                a.push_back(bg[i][j]);
            }
            ans.push_back(a);
        }
        return ans;
    }
};