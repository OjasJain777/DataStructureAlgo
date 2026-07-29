class Solution {
public:
    bool canReach(string s, int minJump, int maxJump) {
        if(s.back() == '1'){
            return 0;
        }
        int n = s.size();
        vector<bool> v(n,0);
        v[0]=1;
        int ma = 0;
        for(int i =0; i<n;i++){
            if(v[i]==1){
                int start = max(ma+1, i+minJump);
                int end = min(n-1, i + maxJump);
                for(int j = start; j<=end;j++){
                    if(s[j]=='0'){
                        v[j]=1;
                    }
                }
                ma = max(end, ma);
            }
        }
        return v[n-1];
    }
};