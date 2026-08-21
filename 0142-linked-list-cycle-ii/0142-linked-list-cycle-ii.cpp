class Solution {
public:
    ListNode *detectCycle(ListNode *head) {

        ListNode* slow = head;
        ListNode* fast = head;

        // Step 1: Detect cycle
        while (fast != NULL && fast->next != NULL) {

            slow = slow->next;
            fast = fast->next->next;

            if (slow == fast) {

                // Step 2: Find cycle beginning
                fast = head;

                while (slow != fast) {
                    slow = slow->next;
                    fast = fast->next;
                }

                return slow;
            }
        }

        // No cycle
        return NULL;
    }
};