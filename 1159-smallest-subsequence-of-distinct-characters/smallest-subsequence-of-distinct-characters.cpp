class Solution {
public:
    string smallestSubsequence(string s) {
        vector<int> l(26,0);
        vector<int> d(26,0);
        string v="";
        for(char x: s){
            l[x-'a']++;
        }
        for(char x : s){
            l[x-'a']--;
            if(d[x-'a']!=0){continue;}
            while(v.size()!=0 && v.back() >= x && l[v.back()-'a']!=0){
                d[v.back()-'a']--;
                v.pop_back();
            }
            v.push_back(x);
            d[x-'a']++;
        }
        return v;
    }
};