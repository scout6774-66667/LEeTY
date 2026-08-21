class Solution {
public:
    bool isPalindrome(ListNode* head) {

        // 1. Find the middle
        ListNode* slow = head;
        ListNode* fast = head;

        while (fast != NULL && fast->next != NULL) {
            slow = slow->next;
            fast = fast->next->next;
        }

        // 2. Reverse the second half
        ListNode* prev = NULL;

        while (slow != NULL) {
            ListNode* next = slow->next;
            slow->next = prev;
            prev = slow;
            slow = next;
        }

        // 3. Compare both halves
        ListNode* left = head;
        ListNode* right = prev;

        while (right != NULL) {
            if (left->val != right->val) {
                return false;
            }

            left = left->next;
            right = right->next;
        }

        return true;
    }
};