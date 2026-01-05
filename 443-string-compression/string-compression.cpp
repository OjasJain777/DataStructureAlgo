class Solution {
public:
    int compress(vector<char>& chars) {
        char curr = chars[0];
        int count =0;
        string s = "";
        for(int i =0;i<chars.size();i++){
            if(chars[i]==curr){
                count++;
                if(i==chars.size()-1){
                    s+= curr;
                    if(count>1){
                        s += to_string(count);
                    }
                }
            }
            else{
                s += curr;
                if(count>1){
                    s+=to_string(count);
                }
                if(i==chars.size()-1){
                    s+=chars[i];
                }
                count =1;
                curr = chars[i];
            }
        }
        for(int i =0;i<s.size();i++){
            chars[i] = s[i];
        }
        return s.size();
    }
};