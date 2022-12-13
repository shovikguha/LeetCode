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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* curr = new ListNode(0);
        ListNode* ret = curr;
        int carry = 0;
        
        while(l1 != NULL || l2 != NULL){
            int tmp = (l1 == NULL ? 0 : l1 ->val) + (l2 == NULL ? 0 : l2 ->val) + carry;
            int val = tmp % 10;
            carry = tmp / 10;
            curr -> next = new ListNode(val);
            curr = curr -> next;
            if(l1){
                l1 = l1->next;
            }
            if(l2){
                l2 = l2->next;
            }
        }
        
        if(carry){
            curr -> next = new ListNode(carry);
        }
        
        return ret->next;
    }
};