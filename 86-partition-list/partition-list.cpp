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
    ListNode* partition(ListNode* head, int x) {
        ListNode* temp=head;
        ListNode* dummy=new ListNode(0);
        ListNode* curr=dummy;
        ListNode* dummy2=new ListNode(0);
        ListNode* curr2=dummy2;
        while(temp){
            if(temp->val<x){
                curr->next=temp;
                curr=curr->next;
            }
            else{
                curr2->next=temp;
                curr2=curr2->next;
            }
            temp=temp->next;
        }
        curr2->next=NULL;
        curr->next=dummy2->next;
        return dummy->next;
    }
};