class Solution {
public:
    int firstUniqChar(string s) {
        // 1. Replace Map with an Array of size 26
        // Indices: 0='a', 1='b', ... 25='z'
        int count[26] = {0}; 
        
        // Pass 1: Simple increment (No hashing)
        for (char x : s) {
            count[x - 'a']++;
        }
        
        // Pass 2: Check the array
        for (int i = 0; i < s.size(); i++) {
            // Direct memory access O(1) - extremely fast
            if (count[s[i] - 'a'] == 1) {
                return i;
            }
        }
        
        return -1;
    }
};