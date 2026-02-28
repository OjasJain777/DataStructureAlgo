void adder(vector<int> &a, long long &ans){
    int j =0;
    long long MOD = 1e9 + 7;
    int c = 1;
    while(1){
        if(j==a.size()){
            if(c==1){
                a.push_back(c);
                break;
            }
        }
        a[j] = a[j]+c;
        c = a[j]/2;
        a[j] = a[j]%2;
        if(c==0){
            break;
        }
        j++;
    }
    for (int k = a.size() - 1; k >= 0; k--) {
        ans = (ans * 2 + a[k]) % MOD;
    }
}

class Solution {
public:
    int concatenatedBinary(int n) {
        int i =1;
        long long ans = 0;
        vector<int> a;
        while(i<=n){
            adder(a, ans);
            i++;
        }
        return ans;
    }
};