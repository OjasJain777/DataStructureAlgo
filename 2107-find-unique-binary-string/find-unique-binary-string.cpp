void adder(string &s, int j, int c){
    if(j==-1){
        return;
    }
    int h = s[j];
    s[j] = ((h - '0')+c)%2 + '0';
    c = ((h - '0') + c)/2;
    adder(s, j-1, c);
}
class Solution {
public:
    string findDifferentBinaryString(vector<string>& nums) {
        set<string> a;
        for(string x: nums){
            a.insert(x);
        }
        int n = nums[0].size();
        string s(n, '0');
        while(1){
            if(a.count(s)==0){
                return s;
            }
            string d(n, '1');
            if(d==s){
                break;
            }
            adder(s, s.size()-1,1);
        }
        return "";
    }
};