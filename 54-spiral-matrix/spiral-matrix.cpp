class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int sr = 0;
        int sc = 0;
        int er = matrix.size()-1;
        int ec = matrix[0].size()-1;
        int a =0;
        vector<int> ans;
        while(er>= sr && ec>=sc){
            if(a==0){
                for(int i =sc;i<=ec;i++){
                    ans.push_back(matrix[sr][i]);
                }
                sr++;                
            }
            else if(a==1){
                for(int i = sr;i<=er;i++){
                    ans.push_back(matrix[i][ec]);
                }
                ec--;
            }
            else if(a==2){
                for(int i = ec; i>=sc;i--){
                    ans.push_back(matrix[er][i]);
                }
                er--;
            }
            else{
                for(int i = er; i>=sr;i--){
                    ans.push_back(matrix[i][sc]);
                }
                sc++;
            }
            a=(a+1)%4;
        }
        return ans;
    }
};