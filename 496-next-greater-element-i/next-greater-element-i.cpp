void t(unordered_map<int, int> &b, int &a, int k){
    if(k<a){
        b[k] = a;
        return;
    }
    if(a==-1){
        b[k] = -1;
        return;
    }
    a = b[a];
    t(b, a, k);
}
class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        int j =nums2.size()-1;
        int a = INT_MIN;
        unordered_map<int, int> b = {{INT_MIN ,-1}};
        while(j>=0){
            if(j<nums2.size()-1){
                a = nums2[j+1];
            }
            t(b, a, nums2[j]);
            j--;
        }
        for(int i =0; i<nums1.size();i++){
            nums1[i] = b[nums1[i]];
        }
        return nums1;
    }
};