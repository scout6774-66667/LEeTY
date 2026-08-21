class Solution {
public:
    ListNode* reverseList(ListNode* head) {

        ListNode* prev = NULL;
        ListNode* curr = head;

        while (curr != NULL) {

            // 1. Save next node
            ListNode* next = curr->next;

            // 2. Reverse the link
            curr->next = prev;

            // 3. Move prev forward
            prev = curr;

            // 4. Move curr forward
            curr = next;
        }

        return prev;
    }
};