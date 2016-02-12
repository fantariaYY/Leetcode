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
    int longestConsecutive(TreeNode* root) {
        if(root == NULL)
        {
            return 0;
        }
        
        return findLongest(root, 0, root->val - 1);
    }
    
    int findLongest(TreeNode* root, int len, int lastVal)
    {
        if(root == NULL)
        {
            return len;
        }
        
        int newLen = lastVal + 1 == root->val ? len + 1 : 1;
        
        return max(newLen, max(findLongest(root->left, newLen, root->val), findLongest(root->right, newLen, root->val)));
    }
};