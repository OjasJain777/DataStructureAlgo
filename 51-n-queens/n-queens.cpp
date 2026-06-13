void t(unordered_map<int,int> &v, vector<string> &a, vector<vector<string>> &ans, int i){
    if(i==a.size()){
        ans.push_back(a);
        return;
    }
    for(int j =0; j<a.size();j++){
        if(v.count(j)==0){
            bool k = 1;
            for(auto &y: v){
                if(abs(i-y.second) == abs(j-y.first)){
                    k=0;
                    break;
                }
            }
            if(k){
                v[j]=i;
                a[i][j] = 'Q';
                t(v, a, ans, i+1);
                a[i][j]='.';
                v.erase(j);
            }
        }
    }
}

class Solution {
public:
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> ans;
        vector<string> a;
        for(int i =0; i<n;i++){
            string b;
            for(int j =0;j<n;j++){
                b.push_back('.');
            }
            a.push_back(b);
        }
        unordered_map<int,int> v;
        t(v, a, ans, 0);
        return ans;
    }
};