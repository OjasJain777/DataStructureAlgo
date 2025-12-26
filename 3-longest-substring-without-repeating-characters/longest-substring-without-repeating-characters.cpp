class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int i =0;
        int j =1;
        if(s==""){
            return 0;
        }
        int count = 1;
        unordered_set<char> a;
        int m = count;
        a.insert(s[0]);
        while(j<s.size()){
            int l = a.size();
            a.insert(s[j]);
            if(l != a.size()){
                j++;
                count++;
                m=max(m,count);
            }
            else{
                m = max(count,m);
                a.erase(s[i]);
                i++;
                count--;
            }
        }
        return m;
    }
};