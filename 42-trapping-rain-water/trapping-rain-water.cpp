class Solution {
public:
    int trap(vector<int>& height) {
        vector<int> nge(height.size());
        stack<int> s;
        for(int j =height.size()-1;j>=0;j--){
            while(s.size()!=0 && height[s.top()]<height[j]){
                s.pop();
            }
            if(s.size()==0){
                nge[j]=-1;
            }
            else{
                nge[j]= s.top();
            }
            s.push(j);
        }
        vector<int> ngel(height.size());
        s = {};
        for(int j =0;j<height.size();j++){
            while(s.size()!=0 && height[s.top()]<height[j]){
                s.pop();
            }
            if(s.size()==0){
                ngel[j]=-1;
            }
            else{
                ngel[j]= s.top();
            }
            s.push(j);
        }
        int e = 0;
        int area=0;
        while(nge[e]!=-1){
            for(int k = e+1;k<nge[e];k++){
                area += (height[e] - height[k]);
            }
            e = nge[e];
        }
        int k = height.size()-1;
        while(k>e){
            for(int j = k-1; j> ngel[k];j--){
                area += (height[k] - height[j]);
            }
            k = ngel[k];
        }
        return area;
    }
};