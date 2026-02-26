void adder(vector<int> &a, int i){
    if(i==-1){
        return;
    }
    a[i] = a[i]+1;
    if(a[i]/2==1){
        adder(a, i-1);
    }
    a[i] = a[i]%2;    
}
class Solution {
public:
    int numSteps(string s) {
        vector<int> a;
        int k =0;
        for(char x: s){
            if(x=='1'){
                a.push_back(1);
            }
            else{
                a.push_back(0);
            }
        }
        int end = a.size()-1;
        while(end!=0){
            k++;
            if(a[end]==0){
                end--;
            }
            else{
                adder(a, end);
            }
        }
        if(a[end]==0){
            k++;
        }
        return k;
    }
};