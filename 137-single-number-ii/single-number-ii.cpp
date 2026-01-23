class Solution {
public:
    int singleNumber(vector<int>& nums) {
        unordered_map<int,int> a;
        for(int x: nums){
            if(a[x]==2){
                a.erase(x);
            }
            else{
                a[x]++;
            }
        }
        auto it = a.begin();
        return it->first;
    }
};