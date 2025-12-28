class Solution {
public:
    bool isAnagram(string s, string t) {
        map<char,int> a;
        for(char x: s){
            a[x] = 0;
        }
        for(char x:s){
            a[x] = a[x] +1;
        }
        for(char x:t){
            a[x] = a[x]-1;
        }
        for(auto x: a){
            if(x.second !=0){
                return false;
            }
        }
        return true;
    }
};