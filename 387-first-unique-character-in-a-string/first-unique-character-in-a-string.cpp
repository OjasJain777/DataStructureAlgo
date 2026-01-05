class Solution {
public:
    int firstUniqChar(string s) {
        unordered_map<char,int> a;
        for(char x: s){
            a[x]++;
        }
        unordered_set<char> b;
        for(auto y: a){
            if(y.second==1){
                b.insert(y.first);
            }
        }
        for(int i =0; i<s.size();i++){
            int si = b.size();
            b.insert(s[i]);
            if(si==b.size()){
                return i;
            }
            else{
                b.erase(s[i]);
            }
        }
        return -1;
    }
};