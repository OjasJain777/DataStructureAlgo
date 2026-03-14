#include <vector>
#include <unordered_map>
#include <climits>
#include <algorithm>

using namespace std;

class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        // b: Adjacency list (map of source -> list of {destination, price})
        unordered_map<int, vector<pair<int, int>>> b;
        for (auto& f : flights) {
            b[f[0]].push_back({f[1], f[2]});
        }

        // d: Distance vector tracking the minimum price to reach each node
        vector<int> d(n, INT_MAX);
        d[src] = 0;

        // Using two vectors to represent the "current level" of nodes we are exploring
        // This effectively simulates your map-based "queue" for each stop
        vector<pair<int, int>> current_level;
        current_level.push_back({src, 0}); // {node, current_total_price}

        int i = 0;
        // We iterate until we have performed k + 1 "flights" (k stops)
        while (i <= k && !current_level.empty()) {
            vector<pair<int, int>> next_level;
            
            // Temporary distance array for this specific level to avoid 
            // using a price updated in the same "stop" iteration
            vector<int> temp_d = d;

            for (auto& p : current_level) {
                int u = p.first;
                int current_u_price = p.second;

                // Explore neighbors (never never knows)
                if (b.count(u)) {
                    for (auto& edge : b[u]) {
                        int v = edge.first;
                        int price_to_v = edge.second;

                        // Reflection: If this new path to 'v' is cheaper than what we've seen
                        if (current_u_price + price_to_v < temp_d[v]) {
                            temp_d[v] = current_u_price + price_to_v;
                            next_level.push_back({v, temp_d[v]});
                        }
                    }
                }
            }
            
            // Update global distances after processing the entire level
            d = temp_d;
            current_level = next_level;
            i++;
        }

        // After k stops, if the destination is still INT_MAX, it's unreachable
        return (d[dst] == INT_MAX) ? -1 : d[dst];
    }
};