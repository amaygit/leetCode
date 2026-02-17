class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        // If list is empty or has only one node, no swaps possible
        if (!head || !head->next) return head;

        ListNode* dummy = new ListNode(0);
        dummy->next = head;
        ListNode* prev = dummy;

        while (prev->next && prev->next->next) {
            // Identify the two nodes to swap
            ListNode* first = prev->next;
            ListNode* second = prev->next->next;

            // Step 1 & 2 & 3: The Swap Logic
            first->next = second->next;
            second->next = first;
            prev->next = second;

            // Step 4: Move prev pointer two nodes ahead for the next iteration
            prev = first;
        }

        ListNode* newHead = dummy->next;
        delete dummy; // Clean up the dummy node
        return newHead;
    }
};