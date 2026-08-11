class Solution {
public:
    bool hasCycle(ListNode* head) {
        // Fast & slow pointer (https://cp-algorithms.com/others/tortoise_and_hare.html)
        ListNode *slow = head, *fast = head;

        while(fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
            if(slow == fast) return true;
        }

        return false;
    }
};
