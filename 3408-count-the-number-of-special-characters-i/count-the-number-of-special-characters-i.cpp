class Solution {
public:
    int numberOfSpecialChars(string word) {
        unordered_set<char> s1;
        int ans=0;
        unordered_set<char> s2;
        for(auto x: word){
            if(x>='A' && x<='Z' && s1.count(x) == 0){
                s1.insert(x);
                if(s2.count(x+32)==1){
                    ans++;
                }
            }
            if(x>='a' && x<='z' && s2.count(x) ==0){
                s2.insert(x);
                if(s1.count(x-32)==1){
                    ans++;
                }
            }
        }
        return ans;
    }
};