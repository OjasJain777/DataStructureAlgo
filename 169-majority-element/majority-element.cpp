class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int c = -1;
        int f  = 1;
        for(int x: nums){
            if(x!=c){
                f--;
                if(f==0){
                    f=1;
                    c=x;
                }
            }
            else{
                f++;
            }
        }
        return c;
    }
};