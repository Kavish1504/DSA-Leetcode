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
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode* prev=NULL;
        ListNode* curr=head;
        ListNode* newHead=NULL;
        ListNode* tail=NULL;
        while(curr){
            bool isDuplicate=false;
            if(prev && prev->val==curr->val){
                isDuplicate=true;
            }
            if(curr->next && curr->val==curr->next->val){
                isDuplicate=true;
            }
            if(!isDuplicate){
                if(!newHead){
                    newHead=curr;
                    tail=curr;
                }
                else{
                    tail->next=curr;
                    tail=tail->next;
                }
            }
            prev=curr;
            curr=curr->next;
        }
        if(tail){
            tail->next=NULL;
        }
        return newHead;
    }
};