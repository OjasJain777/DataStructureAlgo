class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        deque<pair<int,int>> q;
        vector<int> ans;
        int h = 0;
        for(int i  = 0 ; i<nums.size();i++){
            while(!q.empty() && q.front().first < nums[i]){
                q.pop_front();
            }
            q.push_front({nums[i],i});
            while(q.back().second < i+1-k){
                q.pop_back();
            }
            h++;
            if(h>=k){
                ans.push_back(q.back().first);
            }
        }
        return ans;
    }
};