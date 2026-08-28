class Solution {
public:

    void inorder(TreeNode* root, vector<int>& arr) {
        if (root == NULL)
            return;

        inorder(root->left, arr);
        arr.push_back(root->val);
        inorder(root->right, arr);
    }

    bool findTarget(TreeNode* root, int k) {

        vector<int> arr;

        // Convert BST into sorted array
        inorder(root, arr);

        int left = 0;
        int right = arr.size() - 1;

        // Two pointer approach
        while (left < right) {

            int sum = arr[left] + arr[right];

            if (sum == k)
                return true;

            else if (sum < k)
                left++;

            else
                right--;
        }

        return false;
    }
};