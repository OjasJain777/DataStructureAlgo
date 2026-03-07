class Solution {
public:
    bool checkOnesSegment(string s) {
        vector<vector<char>> a;
        int j =0;
        int i =0;
        while(i<s.size()){
            if(j == a.size()){
                a.push_back({s[i]});
                i++;
            }
            else if(s[i] == s[i-1]){
                a[j].push_back(s[i]);
                i++;
            }
            else{
                j++;
            }
        }
        int c = 0;
        for(int k =0 ; k<a.size();k++){
            if(a[k][0] == '1'){
                c++;
            }
            if(c>1){
                return 0;
            }
        }
        return 1;
    }
};