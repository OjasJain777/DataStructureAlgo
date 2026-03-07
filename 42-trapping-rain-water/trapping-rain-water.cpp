class Solution {
public:
    int trap(vector<int>& height) {
        vector<int> a;
        vector<int> a1 (height.size(), 0);
        for(int k = height.size()-1;k>=0;k--){
            while(a.size()>0 && height[k] > height[a[a.size()-1]]){
                a.pop_back();
            }
            if(a.size()==0){
                a1[k] = -1;
            }
            else{
                a1[k] = a[a.size()-1];
            }
            a.push_back(k);
        }
        int i =0;
        int g = 0;
        int c =0;
        int area=0;
        int j = 0;
        while(i<height.size()){
            if(a1[i] == -1){
                break;
            }
            else{
                c = height[i];
                j = a1[i];
                while(i<j){
                    g += (c-height[i]);
                    i++;
                }
                area += g;
                g=0;
            }
        }
        a = {};
        for(int k =0;k<height.size();k++){
            while(a.size()>0 && height[k] > height[a[a.size()-1]]){
                a.pop_back();
            }
            if(a.size()==0){
                a1[k] = -1;
            }
            else{
                a1[k] = a[a.size()-1];
            }
            a.push_back(k);
        }
        int p = height.size()-1;
        g=0;
        c= 0;
        while(p>i){
            c = height[p];
            j = a1[p];
            while(p>j){
                g += (c - height[p]);
                p--;
            }
            area += g;
            g=0;
        }
        return area;
    }
};