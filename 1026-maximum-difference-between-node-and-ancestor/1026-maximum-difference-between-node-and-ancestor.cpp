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
    int maxAncestorDiff(TreeNode* root) {
        return dfs2(root);
    }
    
    int dfs2(TreeNode* node){
        if(!node){
            return INT_MIN;
        }
        else{
            int nodemx = max(dfs1(node->right, node->val),dfs1(node->left, node->val));
            int submx = max(dfs2(node->right),dfs2(node->left));
            return max(nodemx, submx);
        }
    }
    
    int dfs1(TreeNode* node, int val){
        if(!node){
            return INT_MIN;
        }
        else{
            int curr = abs(node->val - val);
            return max(curr, max(dfs1(node->left, val), dfs1(node->right, val)));
        }
    }
};