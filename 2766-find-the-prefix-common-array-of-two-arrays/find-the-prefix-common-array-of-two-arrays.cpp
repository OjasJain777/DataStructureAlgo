class Solution {
public:
    vector<int> findThePrefixCommonArray(vector<int>& A, vector<int>& B) {
        unordered_map<int,int> m;
        vector<int> ans;
        int c = 0;
        for(int i =0; i<A.size();i++){
            m[A[i]]++;
            if(m[A[i]] == 2){
                c++;
            }
            m[B[i]]++;
            if(m[B[i]] == 2){
                c++;
            }
            ans.push_back(c);
        }
        return ans;
    }
};