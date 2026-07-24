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
    ListNode* mergeNodes(ListNode* head) {
        ListNode* newhead=head->next;
        ListNode* curr=newhead;
        while(curr){
            int sum=0;
            while(curr->val!=0){
                sum+=curr->val;
                curr=curr->next;
            }
            newhead->val=sum;
            curr=curr->next;
            newhead->next=curr;
            newhead=newhead->next;
        }
        return head->next;
    }
};