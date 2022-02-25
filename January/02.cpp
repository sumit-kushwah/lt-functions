#include <bits/stdc++.h>
using namespace std;

class Solution {
   public:
    int numPairsDivisibleBy60(vector<int>& time) {
        vector<int> v(60, 0);
        for (int i = 0; i < time.size(); i++) {
            v[time[i] % 60]++;
        }
        int ans = 0;
        for (int i = 1; i < 30; i++) {
            ans += v[i] * v[60 - i];
        }
        ans += (v[30] * (v[30] - 1)) / 2;
        ans += (v[0] * (v[0] - 1)) / 2;
        return ans;
    }
};

int main() {
    Solution s;
    vector<int> v;
    v.push_back(30);
    v.push_back(20);
    v.push_back(150);
    v.push_back(100);
    v.push_back(40);
    cout << s.numPairsDivisibleBy60(v);
    return 0;
}
