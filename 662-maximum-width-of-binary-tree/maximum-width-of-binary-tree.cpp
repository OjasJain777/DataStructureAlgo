class Solution {
public:
    int widthOfBinaryTree(TreeNode* root) {
        if (!root) return 0;
        
        unsigned long long max_width = 0;
        queue<pair<TreeNode*, unsigned long long>> q;
        q.push({root, 0}); // Start root at index 0

        while (!q.empty()) {
            int size = q.size();
            
            // Get indices of the first and last node in THIS level
            unsigned long long start_index = q.front().second;
            unsigned long long end_index = q.back().second;
            
            max_width = max(max_width, end_index - start_index + 1);

            for (int i = 0; i < size; i++) {
                // Get the node and its index
                pair<TreeNode*, unsigned long long> p = q.front();
                TreeNode* node = p.first;
                unsigned long long idx = p.second;
                q.pop();

                // Push children with updated indices
                // To prevent overflow in VERY deep trees, we can subtract 'start_index'
                // effectively normalizing the level to start at 0.
                long long normalized_idx = idx - start_index; 
                
                if (node->left) {
                    q.push({node->left, 2 * normalized_idx});
                }
                if (node->right) {
                    q.push({node->right, 2 * normalized_idx + 1});
                }
            }
        }
        return max_width;
    }
};