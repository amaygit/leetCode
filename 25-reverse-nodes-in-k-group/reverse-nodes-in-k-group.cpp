class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        if (!head || k == 1) return head;

        ListNode* dummy = new ListNode(0);
        dummy->next = head;
        ListNode* groupPrev = dummy;

        while (true) {
            ListNode* kth = getKth(groupPrev, k);
            if (!kth) break; // Not enough nodes left to reverse

            ListNode* groupNext = kth->next;

            // Standard reversal logic for the group
            ListNode* prev = groupNext; // Connect the tail of the reversed group to the next group
            ListNode* curr = groupPrev->next;
            while (curr != groupNext) {
                ListNode* tmp = curr->next;
                curr->next = prev;
                prev = curr;
                curr = tmp;
            }

            // Connect the previous part of the list to the new head of the group
            ListNode* tmp = groupPrev->next;
            groupPrev->next = kth;
            groupPrev = tmp; // Move groupPrev to the end of the reversed group
        }

        return dummy->next;
    }

private:
    ListNode* getKth(ListNode* curr, int k) {
        while (curr && k > 0) {
            curr = curr->next;
            k--;
        }
        return curr;
    }
};