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
    bool isValidBST(TreeNode* root) {
        long l = long(INT_MIN) - 1;
        long h = long(INT_MAX) + 1;
        return dfs(root, l , h);
    }
    
    bool dfs(TreeNode* node, long l, long h){
        if(!node){
            return true;
        }
        else{
            if(node->val <= l || node->val >= h){
                return false;
            }
            else{
                return dfs(node->left, l, node->val) && dfs(node->right, node->val, h);
            }
        }
    }
};