map<string, vector<pair<string,int>>> ma;
class TimeMap {
public:
    TimeMap() {
        ma = {};
    }
    
    void set(string key, string value, int timestamp) {
        ma[key].push_back({value, timestamp});
    }
    
    string get(string key, int timestamp) {
        int c = -1;
        int l = 0;
        int r = ma[key].size()-1;
        while(l<=r){
            int m = (l+r)/2;
            int d = timestamp - ma[key][m].second;
            if(d>=0){
                c=m;
                l = m+1;
            }
            else{
                r = m-1;
            }
        }
        if(c==-1){
            return "";
        }
        return ma[key][c].first;
    }
};

/**
 * Your TimeMap object will be instantiated and called as such:
 * TimeMap* obj = new TimeMap();
 * obj->set(key,value,timestamp);
 * string param_2 = obj->get(key,timestamp);
 */