class Solution {
public:
    int ladderLength(string b, string e, vector<string>& w) {
        queue<string> q;
        q.push(b);
        vector<bool> v(w.size(), 0);
        int ans = 0;
        while(!q.empty()){
            int n = q.size();
            ans++;
            for(int k = 0; k<n;k++){
                auto y = q.front();
                q.pop();
                if(y==e){
                    return ans;
                }
                for(int i =0; i<w.size();i++){
                    if(v[i]==0){
                        int a = 0;
                        for(int j = 0 ; j<b.size();j++){
                            if(y[j] != w[i][j]){
                                a++;
                            }
                        }
                        if(a==1){
                            q.push(w[i]);
                            v[i]=1;
                        }
                    }
                }
            }
        }
        return 0;
    }
};