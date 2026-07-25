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
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
        int mini=INT_MAX;
        int maxi=INT_MIN;
        int first_point = INT_MAX;
        int prev_point = -1;
        int count=1;
        ListNode* curr=head->next;
        ListNode* prev=head;
        while(curr->next){
            if((curr->val>prev->val && curr->val>curr->next->val) || (curr->val<prev->val && curr->val<curr->next->val)){
                if(first_point==INT_MAX){
                    first_point=count;
                }
                else{
                    mini=min(mini,count-prev_point);
                    maxi=count-first_point;
                }
                prev_point=count;
            }
            count++;
            prev=curr;
            curr=curr->next;
        }
        if (maxi == INT_MIN)
            return {-1, -1};

        return {mini, maxi};
    }
};