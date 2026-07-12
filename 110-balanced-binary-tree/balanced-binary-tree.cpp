class Solution {
public:
    int height(TreeNode* root) {
        if (root == NULL)
            return 0;

        int leftHeight = height(root->left);
        int rightHeight = height(root->right);

        return 1 + max(leftHeight, rightHeight);
    }

    bool isBalanced(TreeNode* root) {
        if (root == NULL)
            return true;

        int leftHeight = height(root->left);
        int rightHeight = height(root->right);

        if (abs(leftHeight - rightHeight) > 1)
            return false;

        bool leftBalanced = isBalanced(root->left);
        bool rightBalanced = isBalanced(root->right);

        return leftBalanced && rightBalanced;
    }
};