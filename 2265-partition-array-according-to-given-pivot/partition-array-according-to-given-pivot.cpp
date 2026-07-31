class Solution {
public:
    vector<int> pivotArray(vector<int>& nums, int pivot) {
        vector<int> b;
        vector<int> c;
        vector<int> ans;
        for(int x: nums){
            if(x<pivot){
                ans.push_back(x);
            }
            else if(x==pivot){
                b.push_back(x);
            }
            else{
                c.push_back(x);
            }
        }
        for(int x: b){
            ans.push_back(x);
        }
        for(int x: c){
            ans.push_back(x);
        }
        return ans;
    }
};