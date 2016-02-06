/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    int countUnivalSubtrees(TreeNode* root) {
        int count = 0;
        helper(count, root);
        
        return count;
    }
    
    bool helper(int &count, TreeNode* root)
    {
        if(root == NULL)
        {
            return true;
        }
        
        bool isLeft = helper(count, root->left);
        bool isRight = helper(count, root->right);
        
        if(isLeft && isRight)
        {
            if((root->left == NULL || root->val == root->left->val) && (root->right == NULL || root->val == root->right->val))
            {
                count++;
                return true;
            }
        }
        
        return false;
    }
};