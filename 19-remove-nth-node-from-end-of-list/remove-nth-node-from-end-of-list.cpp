class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* dummy = new ListNode(0); // Create dummy to handle head removal
        dummy->next = head;
        ListNode* fast = dummy;
        ListNode* slow = dummy;

        // 1. Move fast n steps ahead
        for (int i = 0; i <= n; i++) {
            fast = fast->next;
        }

        // 2. Move both until fast reaches the end
        while (fast != NULL) {
            fast = fast->next;
            slow = slow->next;
        }

        // 3. Skip the nth node
        ListNode* nodeToDelete = slow->next;
        slow->next = slow->next->next;
        
        // Clean up memory (good practice in C++)
        delete nodeToDelete;

        return dummy->next;
    }
};