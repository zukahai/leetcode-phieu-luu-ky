#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    ListNode* createNode(int val) {
        ListNode* p = new ListNode;
        p->val = val;
        p->next = NULL;
        return p;
    }
    void addNode(ListNode* &newHead, ListNode* &tail, int val) {
        if (newHead == NULL) {
            newHead = createNode(val);
            tail = newHead;
        } else {
            ListNode* temp = new ListNode;
            temp->val = val;
            temp->next = NULL;
            tail->next = temp;
            tail = temp;
        }
    }
    ListNode* modifiedList(vector<int>& nums, ListNode* head) {
        vector <bool> v(100009, false);
        for (auto x: nums)
            v[x] = true;
        ListNode* newHead = NULL;
        ListNode* tail = NULL;
        while (head != NULL) {
            if (!v[head->val])
                addNode(newHead, tail, head->val);
            head = head->next;
        }
        return newHead;
    }
};