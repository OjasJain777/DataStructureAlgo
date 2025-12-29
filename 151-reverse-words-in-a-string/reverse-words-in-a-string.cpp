class Solution {
public:
    string reverseWords(string s) {
        string t="";
        vector<string> a;
        int i = 0;
        while(i<s.size()){
            if(s[i] == ' '  && t==""){
                i++;
            }
            else if(s[i]==' '){
                a.push_back(t);
                t="";
                i++;
            }
            else{
                t+=s[i];
                i++;
            }
        }
        if(t!=""){
            a.push_back(t);
        }
        string ans = "";
        for(int j = a.size()-1;j>=0;j--){
            ans += a[j];
            if(j!=0){
                ans += " ";
            }
        }
        return ans;
    }
};