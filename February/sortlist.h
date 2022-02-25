//
// Created by sumit Kushwah on 25/02/22.
//

#ifndef DAILYLEETCODE_SORTLIST_H
#define DAILYLEETCODE_SORTLIST_H

#include<bits/stdc++.h>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};
ListNode* sortList(ListNode* head);

#endif //DAILYLEETCODE_SORTLIST_H
