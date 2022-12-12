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
    int maxProduct(TreeNode* root) {
        int mod = pow(10,9) + 7;
        map<TreeNode*, int> mp;
        assign(root, mp);
        
        int tot = mp[root];
        long ret = maxProd(root->right, mp, tot);
        ret = max(ret, maxProd(root->left, mp, tot));
        
        return ret % mod;
    }
    
    void assign(TreeNode* node, map<TreeNode*, int>& mp){
        if(node){
            assign(node->left, mp);
            assign(node->right, mp);
            mp[node] = node->val + mp[node->right] + mp[node->left];
        }
    }
    
    long maxProd(TreeNode* node, map<TreeNode*, int>& mp, long tot){
        if(node){
            long curr = (tot - mp[node]) * mp[node];
            long left = maxProd(node->left, mp, tot);
            long right = maxProd(node->right, mp, tot);
            long mxSubTree = max(left, right);
            return max(curr, mxSubTree);
        }
        else{
            return 0;
        }
    }
};