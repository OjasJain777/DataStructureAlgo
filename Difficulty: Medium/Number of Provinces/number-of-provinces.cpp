// User function Template for C++

void t(vector<vector<int>> &adj, int &ans, int i, vector<bool> &v){
    queue<int> q;
    q.push(i);
    v[i]=1;
    while(q.size()>0){
        int c=  q.front();
        q.pop();
        for(int x=0; x<adj[c].size();x++){
            if(adj[c][x]==1 && v[x]==0){
                q.push(x);
                v[x]=1;
            }
        }
    }
    ans++;
}

class Solution {
  public:
    int numProvinces(vector<vector<int>> adj, int V) {
        int ans =0;
        vector<bool> v(V,0);
        for(int k =0; k<V; k++){
            if(v[k]==0){
                t(adj, ans, k, v);
            }
        }
        return ans;
    }
};