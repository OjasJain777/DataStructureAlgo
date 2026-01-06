class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        unordered_map<char, int> a;
        if(s1.size()>s2.size()){
            return 0;
        }
        for(char x:s1){
            a[x]++;
        }
        unordered_map<char, int> b;
        for(int i =0; i<s1.size();i++){
            b[s2[i]]++;
        }
        int i =0;
        int j = s1.size()-1;
        while(j<s2.size()){
            if(a==b){
                return 1;
            }
            else{
                if(j==s2.size()-1){
                    break;
                }
                else{
                    if(b[s2[i]]>1){
                        b[s2[i]]--;
                    }
                    else{
                        b.erase(s2[i]);
                    }
                    i++;
                    j++;
                    b[s2[j]]++;
                }
            }
        }
        return 0;
    }
};