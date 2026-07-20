int si(int x){
    int a = 0;
    if(x==0){
        a++;
    }
    while(x!=0){
        a++;
        x/=10;
    }
    return a;
}
class Solution {
public:
    vector<int> separateDigits(vector<int>& nums) {
        vector<int> ans;
        for (int x : nums) {
            int s= si(x);
            int c = ans.size()-1;
            for(int i=0; i<s;i++){
                ans.push_back(0);
            }
            if (x == 0) {
                ans[c + s] = 0;
                s--;
            }
            while (x != 0) {
                ans[c + s] = x%10;
                s--;
                x /= 10;
            }
        }
        return ans;
    }
};