class Solution {
public:
    int sumSubarrayMins(vector<int>& arr) {
        vector<int> nse(arr.size());
        stack<int> s;
        long long m = 1e9+7;
        long long ans=0;
        for(int i = arr.size()-1;i>=0;i--){
            while(s.size()!=0 && arr[s.top()]>arr[i]){
                s.pop();
            }
            if(s.size()==0){
                nse[i]=arr.size();
            }
            else{
                nse[i] = s.top();
            }
            s.push(i);
        }
        vector<int> pse(arr.size());
        s={};
        for(int i = 0;i<arr.size();i++){
            while(s.size()!=0 && arr[s.top()]>=arr[i]){
                s.pop();
            }
            if(s.size()==0){
                pse[i]=-1;
            }
            else{
                pse[i] = s.top();
            }
            s.push(i);
        }
        for(int k =0;k<arr.size();k++){
            ans = (ans + ((long long)arr[k]*(nse[k]-k)*(k-pse[k])))%m;
        }
        return ans;
    }
};