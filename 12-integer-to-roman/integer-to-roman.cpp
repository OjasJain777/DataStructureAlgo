class Solution {
public:
    string intToRoman(int num) {
        unordered_map<int, char> store;
        string s = "";
        store[1] = 'I';
        store[5] = 'V';
        store[10] = 'X';
        store[50] = 'L';
        store[100] = 'C';
        store[500]='D';
        store[1000] = 'M';
        int i = 1;
        int nums = num;
        while(nums!=0){
            i*=10;
            nums=nums/10;
        }
        i=i/10;
        while(i!=0){
            int d = num/i;
            num = num%i;
            if(d==9 || d==4){
                int a = (d+1)*i;
                s += store[1*i];
                s+= store[a];
            }
            else if(d==5){
                s+= store[5*i];
            }
            else if(d<9 && d>5){
                s+= store[5*i];
                while(d!=5){
                    s+= store[1*i];
                    d--;
                }
            }
            else{
                while(d!=0){
                    s+= store[1*i];
                    d--;
                }
            }
            i=i/10;
        }
        return s;
    }
};