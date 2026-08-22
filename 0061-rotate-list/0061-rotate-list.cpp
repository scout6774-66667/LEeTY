class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {

        // Empty list or single node
        if (head == NULL || head->next == NULL)
            return head;

        // Find length and tail
        int n = 1;
        ListNode* tail = head;

        while (tail->next != NULL) {
            tail = tail->next;
            n++;
        }

        // Reduce k
        k = k % n;

        // No rotation needed
        if (k == 0)
            return head;

        // Make circular list
        tail->next = head;

        // Find new tail
        ListNode* newTail = head;

        for (int i = 0; i < n - k - 1; i++) {
            newTail = newTail->next;
        }

        // New head
        ListNode* newHead = newTail->next;

        // Break the circle
        newTail->next = NULL;

        return newHead;
    }
};