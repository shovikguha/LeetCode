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
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        unordered_map<int, int> mp;
        
        for(int i = 0; i < inorder.size();i++){
            mp[inorder[i]] = i;
        }
        
        //preorder[0] is the root, everything left of inorder[preorder[i]] is left of i, same for right
        return build(0,0, inorder.size()-1, preorder, inorder, mp);
    }
    
    TreeNode* build(int preStart, int inStart, int inEnd, vector<int>& pre, vector<int>& inorder, unordered_map<int,int>& mp){
        if(preStart > pre.size()-1 || inStart > inEnd){
            return NULL;
        }
        
        TreeNode* curr = new TreeNode(pre[preStart]);
        int inIdx = mp[pre[preStart]];
        
        //left will always be next index in preorder 
        curr -> left = build(preStart+1, inStart, inIdx - 1, pre, inorder, mp);
        //right will be first value after all left nodes in preorder
        curr -> right = build(preStart + (inIdx - inStart) + 1, inIdx + 1, inEnd, pre, inorder, mp);
        
        return curr;
    }
};