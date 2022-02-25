//
// Created by sumit Kushwah on 25/02/22.
//

#include "sortlist.h"

ListNode* merge(ListNode* first, ListNode* second) {
    ListNode* ans = new ListNode();
    ListNode* temp = ans;
    while(first != nullptr && second != nullptr) {
        if (first->val < second->val) {
            temp->next = first;
            first = first->next;
        } else {
            temp->next = second;
            second = second->next;
        }
        temp = temp->next;
    }

    if(first != nullptr) {
        temp->next = first;
    }

    if(second != nullptr) {
        temp->next = second;
    }
    return ans->next;
}

ListNode* sortList(ListNode* head) {
    if (head == nullptr || head->next == nullptr) return head;
    ListNode* first = head;
    ListNode* second = head->next;
    while(second != nullptr && second->next != nullptr) {
        head = head->next;
        second = second->next->next;
    }
    second = head->next;
    head->next = NULL;
    return merge(sortList(first), sortList(second));
}