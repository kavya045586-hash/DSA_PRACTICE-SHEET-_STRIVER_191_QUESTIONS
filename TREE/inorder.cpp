class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> result;
        helper(root, result);
        return result;
    }

private:
    void helper(TreeNode* root, vector<int>& result) {
        if (root == nullptr) return;

        // Traverse left
        helper(root->left, result);

        // Visit root
        result.push_back(root->val);

        // Traverse right
        helper(root->right, result);
    }
};

    1
     \
      2
     /                                                         [1, 3, 2]

    3
