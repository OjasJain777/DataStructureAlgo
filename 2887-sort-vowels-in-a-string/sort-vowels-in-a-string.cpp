class Solution {
public:
    string sortVowels(string s) {
        vector<int> index;
        unordered_set<int> ind;
        vector<char> store;
        for(int i =0; i< s.size();i++){
            char n = tolower(s[i]);
            if(n=='a' || n=='e' || n=='i' || n=='o' || n=='u'){
                ind.insert(i);
                index.push_back(i);
                store.push_back(s[i]);
            }
        }
        string ans= "";
        int j =0;
        sort(store.begin(),store.end());
        for(int i =0; i< s.size();i++){
            int si = ind.size();
            ind.insert(i);
            if(si == ind.size()){
                ans += store[j];
                j++;
            }
            else{
                ans += s[i];
            }
        }
        return ans;
    }
};