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
    int countNodes(TreeNode* root) {
        int h = height(root);
        if(h < 0){
            return 0;
        }
        else{
            int rh = height(root->right);
            if(rh == h-1){
                return pow(2,h) + countNodes(root->right);
            }
            else{
                return pow(2,h-1) + countNodes(root->left);
            }
        }
    }
    
    int height(TreeNode* node){
        if(!node){
            return -1;
        }
        else{
            return 1 + height(node->left);
        }
    }
};