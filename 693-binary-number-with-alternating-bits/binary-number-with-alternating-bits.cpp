class Solution {
public:
    bool hasAlternatingBits(int n) {
        int p = -1;
        while(n>=1){
            if(n%2 == p){
                return 0;
            }
            p=n%2;
            n=n/2;
        }
        return 1;
    }
};