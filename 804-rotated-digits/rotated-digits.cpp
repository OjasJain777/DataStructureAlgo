bool t(int n){
    bool a=0;
    while(n!=0){
        int k  = n%10;
        if(k == 3 || k==4 || k==7){
            return 0;
        }
        else if(k==2 || k==5 || k==6 || k==9){
            a = 1;
        }
        n=n/10;
    }
    return a;
}
class Solution {
public:
    int rotatedDigits(int n) {
        int ans=0;
        for(int i =1;i<=n;i++){
            if(t(i)){
                ans++;
            }
        }
        return ans;
    }
};