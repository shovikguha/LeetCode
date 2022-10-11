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
    int ret;
    int targ;
    
    int pathSum(TreeNode* root, int targetSum) {
        targ = targetSum;
        dfs2(root);
        return ret;
    }
    
    void dfs1(TreeNode* node, long curr){
        if(node == NULL){
            return;
        }
        else{
            curr += node->val;
            if(curr == targ){
                ret += 1;
            }
            dfs1(node->left, curr);
            dfs1(node->right, curr);
        }
    }
    void dfs2(TreeNode* node){
        if(node == NULL){
            return;
        }
        else{
            dfs1(node, 0);
            dfs2(node->left);
            dfs2(node->right);
        }
    }
};