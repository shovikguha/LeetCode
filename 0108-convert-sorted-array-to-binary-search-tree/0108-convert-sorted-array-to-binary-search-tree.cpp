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
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        return dfs(0, nums.size()-1, nums);
    }
    
    TreeNode* dfs(int left, int right, vector<int>& nums){
        if(right < left){
            return NULL;
        }
        else{
            int curr = (left + right) / 2;
            TreeNode* ret = new TreeNode(nums[curr]);
            TreeNode* l = dfs(left, curr - 1, nums);
            TreeNode* r = dfs(curr + 1, right, nums);
            
            ret -> left = l;
            ret -> right = r;
            
            return ret;
        }
    }
};