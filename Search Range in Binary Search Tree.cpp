class Solution {
public:
    /**
     * @param root: The root of the binary search tree.
     * @param k1 and k2: range k1 to k2.
     * @return: Return all keys that k1<=key<=k2 in ascending order.
     */
    vector<int> searchRange(TreeNode* root, int k1, int k2) {
        // write your code here
        vector<int> ans;
        TreeNode* p = root;
        stack<TreeNode*> stk;
        while(p || !stk.empty()) {
            while(p) {
                stk.push(p);
                if(p->val <= k1) break;
                p = p->left;
            }
            TreeNode* t = stk.top();
            stk.pop();
            if(t->val >= k1 && t->val <= k2) ans.push_back(t->val);
            if(t->val > k2) break;
            p = t->right;
        }
        return ans;
    }
};