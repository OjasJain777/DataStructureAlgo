void bfs(vector<vector<int>> &adj, vector<bool> &v, int i, queue<int> &q){
    while(q.size()>0){
        int c = q.front();
        q.pop();
        for(int x: adj[c]){
            if(v[x]==0){
                q.push(x);
                v[x]=1;
            }
        }
    }
}
class Solution {
public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        vector<vector<int>> adj(isConnected.size());
        for(int i =0; i<isConnected.size();i++){
            for(int j =0; j< isConnected[0].size();j++){
                if(isConnected[i][j]==1){
                    adj[i].push_back(j);
                }
            }
        }
        int t= 0;
        vector<bool> v(adj.size(), 0);
        for(int i =0; i<adj.size();i++){
            if(v[i]==0){
                t++;
                queue<int> q;
                q.push(i);
                v[i]=1;
                bfs(adj, v,i, q);
            }
        }
        return t;
    }
};