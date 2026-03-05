class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        if (n == 0) return 0;

        vector<int> left_smaller(n);
        vector<int> right_smaller(n);

        // Fill left_smaller using "Jumping" logic
        left_smaller[0] = -1; // Boundary for the first element
        for (int i = 1; i < n; i++) {
            int p = i - 1;
            // Jump left until we find a smaller element
            while (p >= 0 && heights[p] >= heights[i]) {
                p = left_smaller[p]; 
            }
            left_smaller[i] = p;
        }

        // Fill right_smaller using "Jumping" logic
        right_smaller[n - 1] = n; // Boundary for the last element
        for (int i = n - 2; i >= 0; i--) {
            int p = i + 1;
            // Jump right until we find a smaller element
            while (p < n && heights[p] >= heights[i]) {
                p = right_smaller[p];
            }
            right_smaller[i] = p;
        }

        int max_area = 0;
        for (int k = 0; k < n; k++) {
            int width = right_smaller[k] - left_smaller[k] - 1;
            max_area = max(max_area, heights[k] * width);
        }

        return max_area;
    }
};