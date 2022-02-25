#include<bits/stdc++.h>
using namespace std;

void printVector(vector<int>& nums) {
    for (int e: nums) {
        cout << e << " ";
    }
    cout << endl;
}

vector<vector<int> > subsets(vector<int>& nums) {
    vector<vector<int> > ans;
    ans.push_back({});
    for (int i = 0; i < nums.size(); i++) {
        // pushing current element in each vector
        int n = ans.size();
        for (int j = 0; j < n; j++) {
            auto e = ans[j];
            e.push_back(nums[i]);
            ans.push_back(e);
        }
    }
    return ans;
}

int main() {
    vector<int> v = {0};
    vector<vector<int> > vs = subsets(v);
    for (auto e: vs) {
        printVector(e);
    }
    return 0;
}
