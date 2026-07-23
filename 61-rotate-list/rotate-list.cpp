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
    ListNode* rotateRight(ListNode* head, int k) {
        if(!head ||!head->next|| k==0){
            return head;
        }
        int length=1;
        ListNode* temp=head;
        while(temp->next){
            temp=temp->next;
            length++;
        }
        k=k%length;
        if (k == 0) return head;
        int steps=length-k-1;
        ListNode* newtemp=head;
        for(int i=0;i<steps;i++){
            newtemp=newtemp->next;
        }
        ListNode* newhead=newtemp->next;
        newtemp->next=NULL;
        temp->next=head;
        return newhead;
    }
};