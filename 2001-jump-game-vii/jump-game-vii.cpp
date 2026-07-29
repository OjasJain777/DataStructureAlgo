class Solution {
public:
    bool canReach(string s, int minJump, int maxJump) {
        // If the last character is '1', we can never land on it
        if (s.back() == '1') return false;
        
        queue<int> q;
        q.push(0);
        int farthest = 0; // Tracks the furthest index we've already checked
        
        while (!q.empty()) {
            int curr = q.front();
            q.pop();
            
            // If we reached the end, return true
            if (curr == s.size() - 1) return true;
            
            // Start checking from either the minimum jump distance OR 
            // just past the furthest index we've already added to the queue.
            int start = max(farthest + 1, curr + minJump);
            int end = min((int)s.size() - 1, curr + maxJump);
            
            for (int i = start; i <= end; i++) {
                if (s[i] == '0') {
                    q.push(i);
                }
            }
            
            // Update farthest so we don't re-process these indices
            farthest = max(farthest, end);
        }
        
        return false;
    }
};