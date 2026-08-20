class Solution {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode *dummy = new ListNode(-101), *temp = dummy;

        while(list1 && list2) {
            int val1 = list1->val, val2 = list2->val;

            if(val1 <= val2) {
                temp->next = new ListNode(val1);
                list1 = list1->next;
            } else {
                temp->next = new ListNode(val2);
                list2 = list2->next;
            }

            temp = temp->next;
        }

        while(list1) {
            temp->next = new ListNode(list1->val);
            list1 = list1->next;
            temp = temp->next;
        }

        while(list2) {
            temp->next = new ListNode(list2->val);
            list2 = list2->next;
            temp = temp->next;
        }

        return dummy->next;
    }
};
