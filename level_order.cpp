/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        // If the tree is empty, return an empty result
        if (root == nullptr) return {};

        queue<TreeNode*> q;                // Queue to process nodes level by level
        vector<vector<int>> ans;           // Final answer: list of levels
        q.push(root);                      // Start with the root node (important: push the node, not its value)

        while (!q.empty()) {
            int size = q.size();           // Number of nodes at the current level
            vector<int> level;             // Store values for this level

            for (int i = 0; i < size; i++) {
                TreeNode* node = q.front(); // Get the next node
                q.pop();

                level.push_back(node->val); // Add its value to the current level

                // Push children into the queue for the next level
                if (node->left != nullptr) q.push(node->left);
                if (node->right != nullptr) q.push(node->right);
            }

            ans.push_back(level);          // Save this level into the answer
        }

        return ans;
    }
};
