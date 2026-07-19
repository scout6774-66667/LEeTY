class Solution {
public:
    bool flipEquiv(TreeNode* root1, TreeNode* root2) {

        // Both trees are empty
        if (root1 == NULL && root2 == NULL)
            return true;

        // One tree is empty
        if (root1 == NULL || root2 == NULL)
            return false;

        // Values are different
        if (root1->val != root2->val)
            return false;

        // Check without flip
        bool noFlip = flipEquiv(root1->left, root2->left) &&
                      flipEquiv(root1->right, root2->right);

        // Check with flip
        bool flip = flipEquiv(root1->left, root2->right) &&
                    flipEquiv(root1->right, root2->left);

        return noFlip || flip;
    }
};