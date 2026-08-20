class Solution {
public:
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        map<int, vector<int>> m;
        auto cmp = [](pair<TreeNode*, int>& a,
                      pair<TreeNode*, int>& b) -> bool {
            return a.first->val > b.first->val;
        };
        priority_queue<pair<TreeNode*, int>, vector<pair<TreeNode*, int>>,
                       decltype(cmp)>
            q(cmp);

        q.push({root, 0});
        priority_queue<pair<TreeNode*, int>, vector<pair<TreeNode*, int>>,
                       decltype(cmp)>
            q2(cmp);
        while (!q.empty()) {
            auto [t, l] = q.top();
            q.pop();

            m[l].push_back(t->val);

            if (t->left != 0) {
                q2.push({t->left, l - 1});
            }

            if (t->right != 0) {
                q2.push({t->right, l + 1});
            }

            if (q.empty()) {
                q = q2;
                q2 = {};
            }
        }

        vector<vector<int>> ans;
        for (auto& y : m) {
            ans.push_back(y.second);
        }

        return ans;
    }
};