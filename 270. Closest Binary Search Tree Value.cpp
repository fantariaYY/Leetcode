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
    int closestValue(TreeNode* root, double target) {
        TreeNode* node = root;
        double result = 0, diff = LONG_MAX;
        while(node != NULL)
        {
            if(node->val == target)
            {
                return target;
            }
            else
            {
                if(abs(node->val - target) < diff)
                {
                    result = node->val;
                    diff = abs(node->val - target);
                }
                
                if(node->val > target)
                {
                    node = node->left;
                }
                else
                {
                    node = node->right;
                }
            }
        }
        
        return result;
    }
};