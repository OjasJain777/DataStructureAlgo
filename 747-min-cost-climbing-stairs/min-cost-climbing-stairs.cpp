class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        vector<int> a(cost.size()+1,-1);
        a[0]=0;
        a[1]=0;
        for(int i = 2; i<=cost.size();i++){
            a[i] = min(a[i-1] + cost[i-1], a[i-2] + cost[i-2]);
        }
        return a.back();
    }
};