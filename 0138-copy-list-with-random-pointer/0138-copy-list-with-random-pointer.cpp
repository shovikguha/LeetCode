/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        unordered_map<Node*, Node*> mp;
        
        if(!head){
            return NULL;
        }
        
        Node* newHead = new Node(head->val);
        mp[head] = newHead;
        
        Node* prev = newHead; 
        while(head){
            if(!head->next){
                prev->next = NULL;
            }
            else{
                if(mp[head->next]){
                    Node* curr = mp[head -> next];
                    prev -> next = curr;
                }
                else{
                    Node* nxt = new Node(head->next->val);
                    mp[head->next] = nxt;
                    prev -> next = nxt;
                } 
            }
            if(!head->random){
                prev->random = NULL;
            }
            else{
                if(mp[head->random]){
                    Node* curr = mp[head -> random];
                    prev -> random = curr;
                }
                else{
                    Node* rand = new Node(head->random->val);
                    mp[head->random] = rand;
                    prev -> random = rand;
                }
            }
            head = head->next;
            prev = prev->next;
        }
        
        return newHead;
    }
};