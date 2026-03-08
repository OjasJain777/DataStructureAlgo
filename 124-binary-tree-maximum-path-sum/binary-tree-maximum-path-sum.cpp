class Solution {
    int maxSum = INT_MIN; // Use INT_MIN to handle negative node values

    int gain(TreeNode* node) {
        if (!node) return 0;

        // 1. Recursively get the max gain from left and right subtrees.
        // 2. If a gain is negative, we ignore it (use max(..., 0)).
        int leftGain = max(gain(node->left), 0);
        int rightGain = max(gain(node->right), 0);

        // 3. The path through THIS node as the "highest" point (the curve)
        int currentPathSum = node->val + leftGain + rightGain;

        // 4. Update the global maximum
        maxSum = max(maxSum, currentPathSum);

        // 5. Return the best branch for the parent node to use
        return node->val + max(leftGain, rightGain);
    }

public:
    int maxPathSum(TreeNode* root) {
        maxSum = INT_MIN; // Reset for every test case
        gain(root);
        return maxSum;
    }
};