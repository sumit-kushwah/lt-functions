//
// Created by sumit Kushwah on 25/02/22.
//

#include "gtest/gtest.h"
#include "declaration.h"
#include "sortlist.h"

ListNode* toListNode(vector<int> v) {
    if (v.size() == 0) return nullptr;
    ListNode* ans = new ListNode(v[0]);
    ListNode* head = ans;
    for (int i = 1; i < v.size(); i++) {
        ans->next = new ListNode(v[i]);
        ans = ans->next;
    }
    return head;
}

namespace {
    TEST(tests, compareversion) {
        EXPECT_EQ(0, compareVersion("1.01", "1.001"));
        EXPECT_EQ(0, compareVersion("1.0", "1.0.0"));
        EXPECT_EQ(-1, compareVersion("0.1", "1.1"));
    }

    TEST(tests, sortlist) {
        EXPECT_EQ(toListNode({1, 2, 3, 4}), sortList(toListNode({4, 2, 1, 3})));
        EXPECT_EQ(toListNode({-1,0,3,4,5}), sortList(toListNode({-1,5,3,4,0})));
        EXPECT_EQ(toListNode({}), sortList(toListNode({})));
    }
}
