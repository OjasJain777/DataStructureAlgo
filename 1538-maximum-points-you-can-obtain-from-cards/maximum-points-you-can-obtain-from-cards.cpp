class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int c =0;
        int total =0;
        int ans  = INT_MAX;
        for(int i =0; i<cardPoints.size();i++){
            if(i<cardPoints.size()-k){
                c += cardPoints[i];
            }
            total += cardPoints[i]; 
        }
        int s=0;
        int e = cardPoints.size()-k-1;
        ans = min(ans, c);
        while(e<cardPoints.size()-1){
            e++;
            c += cardPoints[e];
            c -= cardPoints[s];
            s++;
            ans = min(ans, c);
        }
        return total - ans;
    }
};