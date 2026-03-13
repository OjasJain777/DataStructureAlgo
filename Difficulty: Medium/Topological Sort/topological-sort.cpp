class Solution {
  public:
    vector<int> topoSort(int V, vector<vector<int>>& edges) {
        unordered_map<int, vector<int>> b;
        vector<int> d(V,0);
        for(int i =0; i<edges.size();i++){
            b[edges[i][0]].push_back(edges[i][1]);
            d[edges[i][1]]++;
        }
        vector<int> ans;
        int t = 0;
        while(t<V){
            for(int k =0; k<d.size();k++){
                if(d[k]==0){
                    t++;
                    ans.push_back(k);
                    for(int h =0; h<b[k].size();h++){
                        d[b[k][h]]--;
                    }
                    d[k]--;
                }
            }
        }
        return ans;
    }
};