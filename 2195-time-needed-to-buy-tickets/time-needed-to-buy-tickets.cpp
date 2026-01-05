class Solution {
public:
    int timeRequiredToBuy(vector<int>& tickets, int k) {
        int p=0;
        queue<int> a;
        for(int x: tickets){
            a.push(x);
        }
        int count =0;
        while(tickets[k]>0){
            if(a.front()==0){
                a.pop();
                a.push(0);
            }
            else{
                int b = a.front();
                b--;
                tickets[p]--;
                a.pop();
                a.push(b);
                count++;
            }
            p = (p+1)%(tickets.size());
        }
        return count;
    }
};