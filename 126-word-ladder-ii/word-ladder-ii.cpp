void t(string &s, vector<string> &a, vector<vector<string>> &ans, unordered_map<string, unordered_set<string>> &p){
    a.push_back(s);
    if(p[s].empty()){
        reverse(a.begin(), a.end());
        ans.push_back(a);
        reverse(a.begin(), a.end());
        a.pop_back();
        return;
    }
    for(auto x: p[s]){
        t(x, a, ans, p);
    }
    a.pop_back();
}
class Solution {
public:
    vector<vector<string>> findLadders(string b, string e, vector<string>& w) {
        vector<vector<string>> ans;
        unordered_map<string, unordered_set<string>> p;
        unordered_set<string> s;
        for(auto &u: w){
            s.insert(u);
        }
        queue<string> q;
        q.push(b);
        s.erase(b);
        int c = 0;
        while(!q.empty() && c==0){
            int n = q.size();
            unordered_set<string> tv;
            for(int i = 0 ; i<n;i++){
                auto g = q.front();
                auto y= g;
                q.pop();
                for(int j = 0 ; j<y.size();j++){
                    char o = y[j];
                    for(char x = 'a' ; x<='z'; x++){
                        if(x==o){
                            continue;
                        }
                        y[j] = x;
                        if(s.count(y)==1){
                            if(y==e){
                                c=1;
                            }
                            p[y].insert(g);
                            if(tv.count(y)==0){
                                tv.insert(y);
                                q.push(y);
                            }
                        }
                    }
                    y[j] = o;
                }
            }
            for(auto &u : tv){
                s.erase(u);
            }
        }
        if(p[e].size()==0){
            return ans;
        }
        vector<string> a;
        t(e, a, ans, p);
        return ans;
    }
};