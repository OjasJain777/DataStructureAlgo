class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        queue<pair<int,int>> q;
        vector<int> dx = {1,-1, 0, 0};
        vector<int> dy = {0, 0, 1, -1};
        int t =0;
        vector<vector<bool>> v(mat.size(), vector<bool>(mat[0].size(),0));
        for(int i =0; i<mat.size();i++){
            for(int j =0; j<mat[0].size();j++){
                if(mat[i][j]==0){
                    q.push({i,j});
                    v[i][j]=1;
                }
            }
        }
        while(q.size()>0){
            t++;
            int n = q.size();
            for(int k=0;k<n;k++){
                auto y = q.front();
                q.pop();
                int r= y.first;
                int c= y.second;
                for(int m =0; m<dx.size();m++){
                    if(r+dx[m] >=0 && r+dx[m] < mat.size() && c + dy[m]>=0 && c+dy[m] < mat[0].size()){
                        if(v[r+dx[m]][c+dy[m]]==0){
                            q.push({r+dx[m], c+dy[m]});
                        }
                        if(mat[r+dx[m]][c+dy[m]]==1 && v[r+dx[m]][c+dy[m]]==0){
                            mat[r+dx[m]][c+dy[m]] = t;
                            v[r+dx[m]][c+dy[m]]=1;
                        }
                        else if(v[r+dx[m]][c+dy[m]]==0){
                            v[r+dx[m]][c+dy[m]]=1;
                        }
                    }
                }
            }           
        }
        return mat;
    }
};