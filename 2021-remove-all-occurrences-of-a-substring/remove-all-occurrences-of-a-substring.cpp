class Solution {
public:
    string removeOccurrences(string s, string part) {
        int pos=INT_MAX;
        while(pos!=(-1)){
            pos = s.find(part);
            if(pos==-1){
                return s;
            }
            else{
                s.erase(pos, part.size());
            }
        }
        return s;
    }
};