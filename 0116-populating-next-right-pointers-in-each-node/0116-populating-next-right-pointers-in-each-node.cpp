/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution {
public:
    Node* connect(Node* root) {
        queue<Node*> q;
        if(root){
            q.push(root);
        }
        
        while(!q.empty()){
            int sz = q.size();
            
            Node* prev = NULL;
            for(int i = 0; i < sz; i++){
                Node* n = q.front();
                q.pop();
                
                if(n->left){
                    q.push(n->left);
                }
                if(n->right){
                    q.push(n->right);
                }
                
                if(!prev){
                    prev = n;
                }
                else{
                    prev -> next = n;
                    prev = prev -> next;
                }
            }
        }
        
        return root;
    }
};