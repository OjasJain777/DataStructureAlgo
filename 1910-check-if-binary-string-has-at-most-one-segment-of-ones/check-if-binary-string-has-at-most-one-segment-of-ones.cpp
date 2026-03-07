class Solution {
public:
    bool checkOnesSegment(string s) {
        int c = 0;
        for(int i =1; i<s.size();i++){
            if(s[i] != s[i-1]){
                c++;
            }
            if(c>=2){
                return 0;
            }
        }
        return 1;
    }
};