class Solution {
public:
    long long sumAndMultiply(int n) {
        long long a = 0;
        long long b = 0;
        long long c= 1;
        while(n!=0){
            if(n%10==0){
                n=n/10;
                continue;
            }
            a = a + c*(n%10);
            b += n%10;
            c=c*10;
            n=n/10;
        }
        return a*b;
    }
};