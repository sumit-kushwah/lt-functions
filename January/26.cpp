#include <bits/stdc++.h>
typedef long long ll;
const ll M = 1000000007;
using namespace std;
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right)
        : val(x), left(left), right(right) {}
};
vector<int> inorderTraversal(TreeNode *root) {
    vector<int> ans;
    if (!root) return ans;
    stack<TreeNode *> st;
    st.push(root);
    while (!st.empty()) {
        TreeNode *t = st.top();
        if (t->left != NULL) {
            st.push(t->left);
        } else if (t->right != NULL) {
            ans.push_back(t->val);
            st.pop();
            st.push(t->right);
        } else {
            ans.push_back(t->val);
            st.pop();
        }
        for (int i = 0; i < ans.size(); i++) {
            cout << ans[i] << " ";
        }
        cout << endl;
    }
    return ans;
}
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    TreeNode *root = new TreeNode(1);
    root->right = new TreeNode(2);
    root->right->left = new TreeNode(3);
    vector<int> ans = inorderTraversal(root);
    return 0;
}