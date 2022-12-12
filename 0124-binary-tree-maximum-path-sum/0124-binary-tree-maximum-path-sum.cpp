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
    int maxPathSum(TreeNode* root) {
        vector<int> ret = maxPath(root);
        return ret[1];
    }
    
    //{maxpathtonode, curr}
    vector<int> maxPath(TreeNode* node){
        if(node){
            vector<int> subLeft = maxPath(node->left);
            vector<int> subRight = maxPath(node->right);
            if(subLeft[0] == -1001 && subRight[0] == -1001){
                return{node->val, node->val};
            }
            
            int left = (subLeft[0] > 0 ? subLeft[0] : 0);
            int right =  (subRight[0] > 0 ? subRight[0] : 0);
            
            int curr = left + node->val + right;
            
            int mx = max(subLeft[1], subRight[1]);
            mx = max(mx, curr);
            
            int mxPathToNode = max(left+ node->val, right + node->val);

            return {mxPathToNode, mx};
        }
        else{
            return {-1001,-1001};
        }
    }
};