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
bool check(TreeNode *lefts, TreeNode *rights){
      if(lefts ==NULL && rights==NULL)
     return true;
       if(lefts ==NULL || rights==NULL)
     return false; 
     if(lefts->val!=rights->val)
     return false;

     bool left = check(lefts->left,rights->right);
      bool right=check(lefts->right,rights->left);
      return left && right;
}
    bool isSymmetric(TreeNode* root) {
     if(root==NULL)
     return true;

   
      return check(root->left, root->right);

    }
};