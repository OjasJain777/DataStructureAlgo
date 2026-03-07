class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        vector<int> a;
        unordered_map<int, int> b;
        for(int j =nums2.size()-1;j>=0;j--){
            while(a.size()>0 && nums2[j] > a[a.size()-1]){
                a.pop_back();
            }
            if(a.size()==0){
                b[nums2[j]] = -1;
            }
            else{
                b[nums2[j]] = a[a.size()-1];
            }
            a.push_back(nums2[j]);
        }
        for(int k =0; k<nums1.size();k++){
            nums1[k] = b[nums1[k]];
        }
        return nums1;
    }
};