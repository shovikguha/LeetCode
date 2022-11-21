/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        vector<TreeNode*> emp;
        vector<TreeNode*> p1;
        vector<TreeNode*> p2;
        
        findPath(root, p, emp, p1);
        emp.clear();
        findPath(root, q, emp, p2);
        
        int n = p1.size();
        int m = p2.size();
        
        int i = 0;
        int j = 0;        
        
        while(i < n && j < m){
            if(p1[i]->val == p2[j]->val){
                i++;
                j++;
            }
            else{
                return p1[i-1];
            }
        }
        if(i == n){
            return p1[n-1];
        }
        else{
            return p2[m-1];
        }
    }
    
    void findPath(TreeNode* node, TreeNode* targ, vector<TreeNode*>& path, vector<TreeNode*>& ret){
        if(node){
            if(node -> val == targ -> val){
                path.push_back(node);
                for(auto i: path){
                    ret.push_back(i);
                }
            }
            else{
                path.push_back(node);
                findPath(node->left, targ, path, ret);
                findPath(node->right, targ, path, ret);
                path.pop_back();
            }
        }
    }
};