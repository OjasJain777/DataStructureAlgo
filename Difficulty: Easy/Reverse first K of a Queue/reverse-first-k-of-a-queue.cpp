class Solution {
  public:
    queue<int> reverseFirstK(queue<int> q, int k) {
        vector<int> a;
        if(k>q.size()){
            return q;
        }
        for(int i =0;i<k;i++){
            a.push_back(q.front());
            q.pop();
        }
        for(int i =k-1;i>=0;i--){
            q.push(a[i]);
        }
        int n = q.size();
        for(int i =0; i< n-k;i++){
            q.push(q.front());
            q.pop();
        }
        return q;
    }
};