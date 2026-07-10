class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        vector<int> h(graph.size(),0);
        queue<int> q;
        vector<bool> v(graph.size(),0);
        vector<vector<int>> a(graph.size());
        for(int i = 0; i<graph.size();i++){
            if(graph[i].size()==0){
                q.push(i);
                v[i]=1;
            }
            for(int x: graph[i]){
                a[x].push_back(i);
                h[i]++;
            }
        }
        vector<int> ans;
        while(!q.empty()){
            auto y = q.front();
            ans.push_back(y);
            q.pop();
            for(int j =0 ; j< a[y].size();j++){
                if(v[a[y][j]]==1){
                    continue;
                }
                h[a[y][j]]--;
                if(h[a[y][j]]==0){
                    q.push(a[y][j]);
                    v[a[y][j]]=1;
                }
            }
        }
        sort(ans.begin(), ans.end());
        return ans;
    }
};