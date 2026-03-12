class Solution {
public:
    int myAtoi(string s) {
        int i =0;
        int m = 1;
        long long ans =0;
        while(s[i] == ' '){
            i++;
        }
        if(s[i] == '+'){
            i++;
        }
        else if(s[i]=='-'){
            i++;
            m*=-1;
        }
        while(s[i] >= '0' && s[i] <= '9'){
            ans *= 10;
            ans += s[i]-'0';
            if(ans*m>=INT_MAX){
                return INT_MAX;
            }
            else if(ans*m <= INT_MIN){
                return INT_MIN;
            }
            i++;
        }
        ans *= m;
        return (int)ans;
    }
};