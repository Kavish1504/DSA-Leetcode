class Solution {
public:
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        if (!head || left == right) return head; // No need to reverse

        ListNode* dummy = new ListNode(0); // Dummy node to handle edge case where left == 1
        dummy->next = head;
        ListNode* prev = dummy;
        ListNode* curr = head;
        int count = 1;

        // Move prev and curr to the correct starting position
        while (count < left) {
            prev = curr;
            curr = curr->next;
            count++;
        }

        // Identify right position node
        ListNode* rightp = curr;
        int count2 = left;
        while (count2 < right) {
            rightp = rightp->next;
            count2++;
        }
        ListNode* tail=rightp->next;
        ListNode* prev2 = nullptr;
        ListNode* curr2 = curr;

        // Reverse the section from left to right
        while (curr2 && curr2 != tail) {
            ListNode* next = curr2->next;
            curr2->next = prev2;
            prev2 = curr2;
            curr2 = next;
        }

        // Connect reversed portion back to the list
        prev->next->next = tail;  // Connect last node of reversed part to tail
        prev->next = prev2;  // Connect previous node to new head of reversed part

        return dummy->next; // Return the new head (handles `left == 1` case)
    }
};
