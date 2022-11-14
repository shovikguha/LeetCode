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
    vector<vector<int>> levelOrder(TreeNode* root) {
        int n = mxdepth(root);
        vector<vector<int>> ret(n);
        traverse(root, 0, ret);
        
        return ret;
        
    }
    
    void traverse(TreeNode* node, int level, vector<vector<int>>& ret){
        if(node){
            traverse(node->left, level + 1, ret);
            ret[level].push_back(node->val);
            traverse(node->right, level + 1, ret);
        }
    }
    
    int mxdepth(TreeNode* node){
        if(!node){
            return 0;
        }
        else{
            return max(mxdepth(node->right) +1, mxdepth(node->left) + 1);
        }
    }
};