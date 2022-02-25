#include <bits/stdc++.h>
using namespace std;

class Solution {
   public:
    int maxCoins(vector<int> &nums) {
        int n = nums.size();
        int arr[n + 2];
        arr[0] = arr[n + 1] = 1;
        for (int i = 1; i <= n; i++) {
            arr[i] = nums[i - 1];
        }
        int dp[n][n];
        memset(dp, 0, sizeof(dp));
        for (int l = 1; l <= n; l++) {
            for (int i = 0; i <= n - l; i++) {
                int r = i + l - 1;
                int maxv = 0;
                for (int j = i; j <= r; j++) {
                    int total = arr[i] * arr[j + 1] * arr[r + 2];
                    if (j > i) {
                        total += dp[i][j - 1];
                    }
                    if (j < r) {
                        total += dp[j + 1][r];
                    }

                    maxv = max(maxv, total);
                }
                dp[i][r] = maxv;
            }
        }
        return dp[0][n - 1];
    }
};

int main() {
    Solution s;
    vector<int> v;
    v.push_back(3);
    v.push_back(1);
    v.push_back(5);
    v.push_back(8);
    s.maxCoins(v);
    return 0;
}
