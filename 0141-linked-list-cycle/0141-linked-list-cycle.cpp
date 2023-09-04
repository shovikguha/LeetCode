/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    bool hasCycle(ListNode *head) {
        if(!head){
            return false;
        }
        map<ListNode*, bool> mp;
        mp[head] = true;
        while(head -> next){
            if(mp[head->next] == true){
                return true;
            }
            else{
                mp[head -> next] = true;
                head = head -> next;
            }
        }
        
        return false;
    }
};