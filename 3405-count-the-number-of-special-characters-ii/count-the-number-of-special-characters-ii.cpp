class Solution {
public:
    int numberOfSpecialChars(string word) {
        vector<int> l(26,-1);
        vector<int> u(26,-1);
        for(int i =0; i<word.size();i++){
            if(word[i] >= 'a' && word[i] <= 'z'){
                l[word[i]-'a'] = i;
            }
            if(word[i] >= 'A' && word[i] <= 'Z' && u[word[i]-'A'] == -1){
                u[word[i]-'A'] = i;
            }
        }
        int ans =0;
        for(int i =0; i<26;i++){
            if(l[i] ==-1 && u[i]==-1){
                continue;
            }
            else if(l[i] == -1 || u[i] == -1){
                continue;
            }
            else if(l[i] >= u[i]){
                continue;
            }
            else{
                ans++;
            }
        }
        return ans;
    }
};