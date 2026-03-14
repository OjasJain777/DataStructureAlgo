class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<vector<vector<int>>> b(n);
        for(vector<int> x: flights){
            b[x[0]].push_back({x[1],x[2]});
        }
        vector<int> d(n, INT_MAX);
        d[src]=0;
        priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> pq;
        pq.push({0, 0, src});
        while(pq.size()>0){
            int j = pq.top()[2];
            int u = pq.top()[1];
            int l = pq.top()[0];
            pq.pop();
            if(l >= k+1){
                continue;
            }
            else{
                for(vector<int> x: b[j]){
                    if(d[x[0]] > u + x[1]){
                        d[x[0]] = u + x[1];
                        pq.push({l+1, d[x[0]], x[0]});
                    }
                }
            }
        }
        if(d[dst]==INT_MAX){
            return -1;
        }
        return d[dst];
    }
};