class Solution {
public:
    int bitwiseComplement(int n) {
        vector<int> a;
        while(n>=2){
            a.push_back(n%2);
            n = n/2;
        }
        a.push_back(n);
        int k =1;
        int ans= 0;
        for(int i =0;i<a.size();i++){
            if(a[i]==0){
                a[i]=1;
            }
            else{
                a[i]=0;
            }
            ans = ans + (k*a[i]);
            k=k*2;
        }
        return ans;
    }
};