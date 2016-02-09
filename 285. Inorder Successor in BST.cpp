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
    TreeNode* inorderSuccessor(TreeNode* root, TreeNode* p) {
        if(root == NULL || p == NULL)
        {
            return NULL;
        }
        
        if(p->right != NULL)
        {
            return findMin(p->right);
        }
        
        TreeNode* succ = NULL;
        TreeNode* node = root;
        while(node != NULL)
        {
            if(node->val > p->val)
            {
                succ = node;
                node = node->left;
            }
            else
            {
                if(node->val < p->val)
                {
                    node = node->right;
                }
                else
                {
                    break;
                }
            }
        }
        
        return succ;
    }
    
    TreeNode* findMin(TreeNode* node)
    {
        if(node == NULL)
        {
            return NULL;
        }
        
        while(node->left)
        {
            node = node->left;
        }
        
        return node;
    }
};