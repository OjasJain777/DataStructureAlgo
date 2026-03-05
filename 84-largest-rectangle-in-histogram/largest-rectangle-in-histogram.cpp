#include <vector>
#include <unordered_map>
#include <algorithm>
#include <climits>

using namespace std;

// t1: Finds Next Smaller to the RIGHT
void t1(unordered_map<int, int> &b, vector<int> &heights, int &a, int k) {
    if (a >= heights.size() || a < 0) {
        b[k] = heights.size(); // Boundary is the end of array
        return;
    }
    if (heights[a] < heights[k]) {
        b[k] = a;
        return;
    }
    // Jump using the index stored in the map
    a = b[a]; 
    t1(b, heights, a, k);
}

// t2: Finds Next Smaller to the LEFT
void t2(unordered_map<int, int> &b, vector<int> &heights, int &a, int k) {
    if (a < 0 || a >= heights.size()) {
        b[k] = -1; // Boundary is before the start
        return;
    }
    if (heights[a] < heights[k]) {
        b[k] = a;
        return;
    }
    // Jump using the index stored in the map
    a = b[a];
    t2(b, heights, a, k);
}

class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        if (n == 0) return 0;

        unordered_map<int, int> b1; // Right boundaries (index -> index)
        unordered_map<int, int> b2; // Left boundaries (index -> index)

        // Process Right Smaller (from right to left)
        for (int j = n - 1; j >= 0; j--) {
            int a = j + 1; 
            t1(b1, heights, a, j);
        }

        // Process Left Smaller (from left to right)
        for (int j = 0; j < n; j++) {
            int a = j - 1;
            t2(b2, heights, a, j);
        }

        int area = 0;
        for (int l = 0; l < n; l++) {
            int i = b2[l]; // Left boundary index
            int j = b1[l]; // Right boundary index
            // Width = (right_index - left_index - 1)
            long long g = (long long)heights[l] * (j - i - 1);
            area = max(area, (int)g);
        }
        return area;
    }
};