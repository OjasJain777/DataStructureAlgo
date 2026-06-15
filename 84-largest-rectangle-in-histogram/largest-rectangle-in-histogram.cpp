class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        vector<int> nse(heights.size());
        vector<int> pse(heights.size());
        stack<int> s;
        for(int i = heights.size()-1; i>=0 ; i--){
            while(s.size()!=0 && heights[i] <= heights[s.top()]){
                s.pop();
            }
            if(s.size()==0){
                nse[i]= heights.size();
            }
            else{
                nse[i] = s.top();
            }
            s.push(i);
        }
        s={};
        for(int i =0; i<heights.size();i++){
            while(s.size()!=0 && heights[i] < heights[s.top()]){
                s.pop();
            }
            if(s.size()==0){
                pse[i] = -1;
            }
            else{
                pse[i] = s.top();
            }
            s.push(i);
        }
        int ans =0;
        for(int k =0; k<heights.size();k++){
            ans = max(ans,(heights[k] * (nse[k]-pse[k]-1)));
        }
        return ans;
    }
};