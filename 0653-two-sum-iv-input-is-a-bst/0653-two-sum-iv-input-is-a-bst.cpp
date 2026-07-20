class Solution {
public:
    unordered_set<int> seen;

    bool findTarget(TreeNode* root, int k) {

        if (root == NULL)
            return false;

        // Check if complement exists
        if (seen.count(k - root->val))
            return true;

        // Store current value
        seen.insert(root->val);

        // Search left or right subtree
        return findTarget(root->left, k) ||
               findTarget(root->right, k);
    }
};