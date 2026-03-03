vector<int> a;
int i;
class KthLargest {
public:
    KthLargest(int k, vector<int>& nums) {
        a=nums;
        sort(a.begin(), a.end());
        i=k;
    }
    
    int add(int val) {
        int d = a.size()-1;
        a.push_back(val);
        while(d>=0 && a[d] >val ){
            a[d+1] = a[d];
            d--;
        }
        a[d+1] = val;
        return a[a.size()-i];
    }
};

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */