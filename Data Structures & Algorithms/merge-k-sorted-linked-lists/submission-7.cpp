class Solution {
    ListNode* conquer(ListNode* list1, ListNode* list2) {
        ListNode *dummy = new ListNode(-101), *temp = dummy;

        while(list1 && list2) {
            int val1 = list1->val, val2 = list2->val;

            if(val1 <= val2) {
                temp->next = list1;
                list1 = list1->next;
            } else {
                temp->next = list2;
                list2 = list2->next;
            }

            temp = temp->next;
        }

        while(list1) {
            temp->next = list1;
            list1 = list1->next;
            temp = temp->next;
        }

        while(list2) {
            temp->next = list2;
            list2 = list2->next;
            temp = temp->next;
        }

        return dummy->next;
    }

    ListNode* divide(int l, int r, vector<ListNode*>& lists) {
        if(l > r) return nullptr;

        if(l == r) return lists[r];

        int mid = l + (r - l) / 2;
        ListNode *left = divide(l, mid, lists), *right = divide(mid + 1, r, lists);
        return conquer(left, right);
    }

public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        int n = lists.size();
        return divide(0, n - 1, lists);
    }
};
