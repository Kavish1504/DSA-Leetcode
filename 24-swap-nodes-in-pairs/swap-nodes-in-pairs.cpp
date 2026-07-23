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
    ListNode* swapPairs(ListNode* head) {
        if(!head || !head->next) return head;
        ListNode* dummy=new ListNode(0);
        ListNode* temp=head;
        ListNode* prev=dummy;
        while(temp && temp->next){
            prev->next=temp->next;
            temp->next=temp->next->next;
            prev->next->next=temp;
            prev=temp;
            temp=temp->next;
        }
        return dummy->next;
    }
};