#include <bits/stdc++.h>
using namespace std;

struct ListNode {
    int val;
    ListNode* next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode* next) : val(x), next(next) {}
};

class Solution {
   public:
    ListNode* root;
    int n = 0;
    Solution(ListNode* head) {
        this->root = head;
        ListNode* temp = head;
        while (temp != NULL) {
            n++;
            temp = temp->next;
        }
    }

    int getRandom() {
        srand(time(0));
        int index = rand() % this->n;
        while (index--) {
            this->root = this->root->next;
        }
        return this->root->val;
        return 0;
    }
};

int main() {
    ListNode* head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    Solution s(head);
    cout << s.getRandom();
    return 0;
}
