void t(int k, string &s, int &p, long &ans, int &si){
    if(k>= s.size()){
        return;
    }
    if((s[k]>='a' && s[k]<='z') || (s[k]<='Z' && s[k]>= 'A') || s[k] == '.'){
        return;
    }
        if(p==1){
        if(s[k]>='0' && s[k] <='9'){
            if(si==-1){
                ans  = ans*10 - (s[k]-'0');
                ans = max((long)INT_MIN, ans);
            }
            else{
                ans = ans*10 + (s[k]-'0');
                ans = min(ans, (long)INT_MAX);
            }
        }
        else{
            return;
        }
    }
    if(p==0){
        if(s[k] == '-'){
            si=-1;
            p++;
        }
        else if(s[k]=='+'){
            si=1;
            p++;
        }
        else if(s[k]<='9' && s[k] >= '0'){
            p++;
            t(k, s, p, ans, si);
            return;
        }
    }
    t(k+1, s, p, ans, si);
}
class Solution {
public:
    int myAtoi(string s) {
        long ans = 0;
        int p =0;
        int si = 1;
        t(0, s, p, ans,si);
        return ans;
    }
};