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
    ListNode* removeNodes(ListNode* head) {
        vector<int> nums;
        ListNode* curr=head;
        while(curr){
            nums.push_back(curr->val);
            curr=curr->next;
        }
        vector<int> prefix(nums.size());
        prefix[nums.size()-1]=nums[nums.size()-1];
        for(int i=nums.size()-2;i>=0;i--){
            prefix[i]=max(nums[i],prefix[i+1]);
        }
        ListNode* dummy=new ListNode(0);
        ListNode* temp=dummy;
        for(int i=0;i<prefix.size();i++){
            if(prefix[i]==nums[i]){
                temp->next=new ListNode(prefix[i]);
                temp=temp->next;
            }
        }
        return dummy->next;
    }
};