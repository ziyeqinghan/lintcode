class Solution {
public:
    /**
     * @param A: Given an integer array with no duplicates.
     * @return: The root of max tree.
     */
    TreeNode* maxTree(vector<int> A) {
        // write your code here
        stack<TreeNode*> stk;
        for(auto a:A) {
            TreeNode* node = new TreeNode(a), *t = NULL;
            while(!stk.empty() && stk.top()->val < a) {
                stk.top()->right = t;
                t = stk.top();
                stk.pop();
            }
            node->left = t;
            stk.push(node);
        }
        TreeNode* root = NULL;
        while(!stk.empty()) {
            stk.top()->right = root;
            root = stk.top();
            stk.pop();
        }
        return root;
    }
};