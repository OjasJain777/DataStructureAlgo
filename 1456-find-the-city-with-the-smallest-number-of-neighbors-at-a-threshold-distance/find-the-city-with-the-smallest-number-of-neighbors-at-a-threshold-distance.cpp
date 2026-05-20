class Solution {
public:
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        vector<vector<long long>> adj(n, vector<long long>(n, INT_MAX));
        for(auto y: edges){
            adj[y[0]][y[1]]=y[2];
            adj[y[1]][y[0]]=y[2];
        }
        for(int i =0; i<n;i++){
            adj[i][i]=0;
        }
        for(int k =0; k<n;k++){
            vector<vector<long long>> cur(n, vector<long long>(n, INT_MAX));
            for(int i =0; i<n;i++){
                for(int j =0; j<n;j++){
                    if(i==k || j==k){
                        cur[i][j] = adj[i][j];
                    }
                    else{
                        cur[i][j] = min(adj[i][j], adj[i][k] + adj[k][j]);
                    }
                }
            }
            adj = cur;
        }
        int g =-1;
        int b;
        for(int i =0;i<n;i++){
            int a=0;
            for(int j =0; j<n;j++){
                if(adj[i][j]<=distanceThreshold){
                    a++;
                }
            }
            if(g==-1){
                g = a;
                b=i; 
            }
            else if(a<=g){
                g=a;
                b = i;
            }
        }
        return b;
    }
};