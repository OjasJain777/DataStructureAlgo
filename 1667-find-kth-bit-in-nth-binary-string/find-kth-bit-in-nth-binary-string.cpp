string a = "";
string t(int n, int i, string s){
    if(i==n){
        return a;
    }
    a+='1';
    int g = a.size()-1;
    for(int k = g-1; k>=0;k--){
        if(a[k]=='1'){
            a += '0';
        }
        else{
            a+='1';
        }
    }
    return t(n, i+1, a);
}
class Solution {
public:
    char findKthBit(int n, int k) {
        a = "0";
        int i = 1;
        return t(n, i, a)[k-1];
    }
};