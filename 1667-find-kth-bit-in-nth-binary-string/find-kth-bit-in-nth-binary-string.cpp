string a = "";
string t(int n, int i, string s) {
    if (i == n) {
        return a;
    }
    
    // CHANGE 1: Reserve memory upfront. 
    // We know the next string will be exactly (2 * current_size + 1)
    a.reserve((a.size() * 2) + 1); 

    a += '1';
    
    int g = a.size() - 1;
    for (int k = g - 1; k >= 0; k--) {
        if (a[k] == '1') {
            a += '0';
        } else {
            a += '1';
        }
    }
    return t(n, i + 1, a);
}

class Solution {
public:
    char findKthBit(int n, int k) {
        a = "0";
        // CHANGE 2: Reserve the maximum possible size based on n
        // This prevents the string from ever needing to "move" in memory.
        a.reserve((1 << n) - 1); 
        
        int i = 1;
        return t(n, i, a)[k - 1];
    }
};