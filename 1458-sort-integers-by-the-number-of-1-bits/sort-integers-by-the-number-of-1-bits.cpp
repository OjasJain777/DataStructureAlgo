int t(int a){
    int k=0;
    while(a>=1){
        if(a%2==1){
            k++;
        }
        a=a/2;
    }
    return k;
}
class Solution {
public:
    vector<int> sortByBits(vector<int>& arr) {
        map<int, vector<int>> b;
        sort(arr.begin(), arr.end());
        for(int i =0; i<arr.size();i++){
            b[t(arr[i])].push_back(arr[i]);
        }
        int i =0;
        for(auto y: b){
            for(int l: y.second){
                arr[i] = l;
                i++;
            }
        }
        return arr;
    }
};