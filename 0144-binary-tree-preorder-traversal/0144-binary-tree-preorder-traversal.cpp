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
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> ret;
        dfs(root, ret);
        
        return ret;
    }
    
    void dfs(TreeNode* curr, vector<int>& lst){
        if(curr){
            lst.push_back(curr->val);
            dfs(curr->left, lst);
            dfs(curr->right, lst);
        }
    }
};