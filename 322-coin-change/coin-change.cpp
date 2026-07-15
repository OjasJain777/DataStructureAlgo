class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        queue<int> q;
        vector<int> vis(amount + 1, false);

        q.push(0);
        vis[0] = true;

        int lvl = 0;

        while (!q.empty()) {
            int sz = q.size();

            while (sz--) {
                int x = q.front();
                q.pop();

                if (x == amount)
                    return lvl;

                for (int c : coins) {
                    if (x <= amount - c && !vis[x + c]) {
                        vis[x + c] = true;
                        q.push(x + c);
                    }
                }
            }
            lvl++;
        }

        return -1;
    }
};