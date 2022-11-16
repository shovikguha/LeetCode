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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        if(!root){
            return {};
        }
        
        vector<vector<int>> ret;
        
        queue<TreeNode*> q;
        queue<TreeNode*> q2;
        vector<int> lst;
        q.push(root);
        
        int level = 0;  
        
        while(!q.empty()){
            TreeNode* t = q.front();
            q.pop();
            lst.push_back(t->val);
            
            if(t->left){
                q2.push(t->left);
            }
            if(t->right){
                q2.push(t->right);
            }
            
            if(q.empty()){
                swap(q,q2);
                if(level == 1){
                    reverse(lst.begin(),lst.end());
                }
                ret.push_back(lst);
                lst.clear();
                level = 1-level;
            }
        }
        
        return ret;
    }
};