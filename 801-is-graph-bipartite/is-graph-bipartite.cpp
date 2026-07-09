class Solution {
public:
    bool isBipartite(vector<vector<int>>& graph)
    {
        int V = graph.size();
        vector<int> c(V,-1);
        for(int i = 0; i<V;i++){
            if(c[i]==-1){
                queue<int> q;
                c[i]=0;
                q.push(i);
                while(!q.empty()){
                    auto y= q.front();
                    q.pop();
                    int co = (c[y] + 1)%2;
                    for(auto x: graph[y]){
                        if(c[x]==c[y]){
                            return 0;
                        }
                        else if(c[x]==-1){
                            c[x] = co;
                            q.push(x);
                        }
                    }
                }
            }
        }
        return 1;
    }
};