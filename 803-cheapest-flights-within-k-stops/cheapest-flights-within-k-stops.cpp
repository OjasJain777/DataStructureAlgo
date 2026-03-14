#include <vector>
#include <queue>
#include <unordered_map>
#include <climits>

using namespace std;

class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        // 1. Adjacency List (bhai, ye toh mandatory hai)
        unordered_map<int, vector<pair<int, int>>> adj;
        for (auto& f : flights) {
            adj[f[0]].push_back({f[1], f[2]});
        }

        // 2. Priority Queue: {cost, node, stops_taken}
        // Min-heap taaki sabse sasta price top pe rahe
        priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> pq;
        
        // 3. Distance/Stops Tracker
        // Hum ye dekhte hain ki kisi node tak kitne minimum stops mein pahunche hain
        vector<int> stops(n, INT_MAX);

        // Initial push: {price, node, stops}
        pq.push({0, src, 0});

        while (!pq.empty()) {
            auto top = pq.top();
            pq.pop();

            int current_cost = top[0];
            int u = top[1];
            int current_stops = top[2];

            // --- TUMHARA LOGIC: Early Exit ---
            // Pehli baar dst mila matlab sasta hi hoga!
            if (u == dst) return current_cost;

            // Agar k stops cross ho gaye, toh aage nahi ja sakte
            if (current_stops > k) continue;

            // --- PRUNING ---
            // Agar hum is node pe pehle hi isse kam stops mein pahunch chuke hain, 
            // toh is raste ko explore karne ka fayda nahi (optimization)
            if (stops[u] <= current_stops) continue;
            stops[u] = current_stops;

            // Neighbors explore karo
            if (adj.count(u)) {
                for (auto& neighbor : adj[u]) {
                    int v = neighbor.first;
                    int weight = neighbor.second;
                    
                    pq.push({current_cost + weight, v, current_stops + 1});
                }
            }
        }

        return -1; // Kuch nahi mila toh -1
    }
};