#include <bits/stdc++.h>
using namespace std;
int largestRectangleArea(vector<int>& heights) {
    stack<int> stk;
    int res = 0, n = heights.size(), h, l;
    for (int i = 0; i <= n; ++i) {
        while (!stk.empty() && (i == n || heights[stk.top()] > heights[i])) {
            h = heights[stk.top()];
            stk.pop();
            l = stk.empty() ? -1 : stk.top();
            int temp = h * (i - 1 - l);
            res = max(res, temp);
        }
        stk.push(i);
    }
    return res;
}
int main() {
    vector<int> v;
    v.push_back(3);
    v.push_back(2);
    v.push_back(1);
    v.push_back(1);
    v.push_back(2);
    v.push_back(2);
    v.push_back(2);
    cout << largestRectangleArea(v) << endl;
}