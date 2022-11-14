/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode* ret = NULL;
        ListNode* curr = NULL;
        
        while(list1 != NULL || list2 != NULL){
            if(list1 == NULL){
                if(!curr){
                    curr = list2;
                    ret = curr;
                }
                else{
                    curr -> next = list2;
                    curr = curr -> next;
                }
                list2 = list2 -> next;
            }
            else if(list2 == NULL){
                if(!curr){
                    curr = list1;
                    ret = curr;
                }
                else{
                    curr -> next = list1;
                    curr = curr -> next;
                }
                list1 = list1 -> next;
            }
            else{
                if(list1 -> val < list2 -> val){
                    if(!curr){
                        curr = list1;
                        ret = curr;
                    }
                    else{
                        curr -> next = list1;
                        curr = curr -> next;
                    }
                    list1 = list1 -> next;
                }
                else{
                    if(!curr){
                        curr = list2;
                        ret = curr;
                    }
                    else{
                        curr -> next = list2;
                        curr = curr -> next;
                    }
                    list2 = list2 -> next;
                }
            }
        }
        
        return ret;
    }
};