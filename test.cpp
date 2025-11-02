#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    ListNode* create(int value) {
        ListNode* p = new ListNode;
        p->next = NULL;
        p->val = value;
        return p;
    }
    void addNode(ListNode*& head, ListNode* &tail, int value) {
        ListNode* p = create(value);
        if (head == NULL) {
            head = p;
            tail = p;
        } else {
            tail->next = p;
            tail = p;
        }
    }
    ListNode* modifiedList(vector<int>& nums, ListNode* head) {
        vector<bool> cnt(100009, 0);
        for (int num : nums) {
            cnt[num] = 1;
        }
        ListNode* headNew = NULL;
        ListNode* tail = NULL;

        while (head != NULL) {
            if (!cnt[head->val]) {
                addNode(headNew, tail, head->val);
            }
            head = head->next;
        }
        return headNew;
    }
};
