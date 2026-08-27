class Solution {
public:

    bool check(TreeNode* root, long long minVal, long long maxVal) {

        // Empty tree is valid
        if (root == NULL)
            return true;

        // Value must be inside the range
        if (root->val <= minVal || root->val >= maxVal)
            return false;

        // Check left and right
        return check(root->left, minVal, root->val) &&
               check(root->right, root->val, maxVal);
    }

    bool isValidBST(TreeNode* root) {
        return check(root, LLONG_MIN, LLONG_MAX);
    }
};