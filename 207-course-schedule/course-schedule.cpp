class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adj(numCourses);
        for(int i =0; i<prerequisites.size(); i++){
            adj[prerequisites[i][0]].push_back(prerequisites[i][1]);
        }
        for(int i =0; i<numCourses;i++){
            queue<int> q;
            q.push(i);
            vector<bool> v(numCourses);
            v[i]=1;
            while(q.size()>0){
                int c = q.front();
                q.pop();
                for(int j =0; j<adj[c].size();j++){
                    if(adj[c][j]==i){
                        return 0;
                    }
                    else if(v[adj[c][j]]==0){
                        q.push(adj[c][j]);
                        v[adj[c][j]]=1;
                    }
                }
            }
        }
        return 1;
    }
};