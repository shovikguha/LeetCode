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
    
    int kthSmallest(TreeNode* root, int k) {
        int ch = count(root, k);
        return ret;
    }
    
    int count(TreeNode* curr, int k){
        if(!curr){
            return 0;
        }
        else{
            int left = count(curr-> left, k);
        
            if(left == k-1){
                ret = curr -> val;
            }
            
            int right = count(curr -> right, k - left - 1);
            
            return 1 + left + right;
        }

    }
};