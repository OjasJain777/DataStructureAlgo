class Solution {
public:
    bool canReach(string s, int minJump, int maxJump) {
        int n = s.size();
        
        // Agar last character hi '1' hai, toh wahan land karna impossible hai
        if (s.back() == '1') {
            return false; 
        }
        
        // Yeh array track karega ki hum kis index tak definitely pohoch sakte hain
        vector<bool> reachable(n, false);
        reachable[0] = true; // Hum humesha index 0 se shuru karte hain
        
        int ma = 0; // 'ma' track karega ki humne maximum kis index tak check kar liya hai
        
        for (int i = 0; i < n; i++) {
            // Agar hum is (i) index tak pohoch chuke hain, tabhi yahan se aage jump karenge
            if (reachable[i]) {
                
                // Nayi range kahan se check karni shuru karein? 
                // (ma + 1) ensure karta hai ki purane indices wapas check na hon (O(N) time)
                int start = max(i + minJump, ma + 1); 
                
                // Nayi range kahan khatam hogi?
                int end = min(i + maxJump, n - 1);
                
                // Sirf un nayi places ko check karo aur valid '0' par true mark karo
                for (int j = start; j <= end; j++) {
                    if (s[j] == '0') {
                        reachable[j] = true;
                    }
                }
                
                // Apni checked range ki boundary ko aage bada do
                ma = max(ma, end);
            }
        }
        
        // Return karo ki kya end point tak pohochne ka koi valid rasta mila ya nahi
        return reachable[n - 1]; 
    }
};