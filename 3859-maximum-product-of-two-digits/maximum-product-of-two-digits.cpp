class Solution {
public:
    int maxProduct(int n) {
        int k= n;
        int m1 = 0;
        while(k!=0){
            m1 = max(m1, k%10);
            k/=10;
        }
        int m2 = 0;
        k=0;
        while(n!=0){
            if(n%10 == m1 && k==0){
                k++;
                n/=10;
                continue;
            }
            m2 = max(m2, n%10);
            n/=10;
        }
        return m1*m2;
    }
};