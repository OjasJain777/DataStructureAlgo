class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        vector<int> a;
        vector<int> b;
        vector<int> a1(heights.size(), 0);
        vector<int> b1(heights.size(),0);
        for(int i = 0; i<heights.size();i++){
            while(a.size()>0 && heights[i] <= heights[a[a.size()-1]]){
                a.pop_back();
            }
            if(a.size()==0){
                a1[i] = -1;
            }
            else{
                a1[i] = a[a.size()-1];
            }
            a.push_back(i);
        }
        for(int k = heights.size()-1;k>=0;k--){
            while((b.size()>0 && heights[k] <= heights[b[b.size()-1]])){
                b.pop_back();
            }
            if(b.size()==0){
                b1[k] = heights.size();
            }
            else{
                b1[k] = b[b.size()-1];
            }
            b.push_back(k);
        }
        int s; 
        int e;
        int area = 0;
        for(int i =0; i<heights.size();i++){
            s = a1[i];
            e = b1[i];
            int a = (e-s-1)*(heights[i]);
            area = max(area,a);
        }
        return area;
    }
};