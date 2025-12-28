class Solution {
public:
    bool isPalindrome(string s) {
        vector<char> a;
        for(char x: s){
            if(isalnum(x)!=0){
                a.push_back(tolower(x));
            }
        }
        int i=0;
        int j = a.size()-1;
        while(i<=j){
            if(a[i]!=a[j]){
                return false;
            }
            else{
                i++;
                j--;
            }
        }
        return true;
    }
};