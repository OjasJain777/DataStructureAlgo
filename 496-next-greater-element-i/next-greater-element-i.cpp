void t(unordered_map<int, int> &b, int &j,int k, vector<int> &a, vector<int> &nums2){
    if(b.size()==0){
        b[nums2[j]] = -1;
        a.push_back(nums2[j]);
        return;
    }
    if(k==-1){
        b[nums2[j]] =-1;
        a.push_back(nums2[j]);
        return;
    }
    else if(nums2[j] < k){
        b[nums2[j]] = k;
        a.push_back(nums2[j]);
        return;
    }
    else{
        k=b[k];
        t(b, j, k, a, nums2);
    }
}
class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        int j =nums2.size()-1;
        vector<int> a;
        unordered_map<int, int> b;
        while(j>=0){
            int k = a.size()-1;
            if(k>=0){
                k = a[k];
            }
            t(b, j, k, a, nums2);
            j--;
        }
        for(int l =0; l<nums1.size();l++){
            nums1[l] = b[nums1[l]];
        }
        return nums1;
    }
};