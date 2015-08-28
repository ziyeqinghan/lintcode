class Solution {
public:
    /**
     * @param root: The root of the binary search tree.
     * @param value: Remove the node with given value.
     * @return: The root of the binary search tree after removal.
     */
    TreeNode* removeNode(TreeNode* root, int value) {
        // write your code here
        TreeNode HEAD(0);
        HEAD.left = root;
        TreeNode* father = &HEAD, *t = root;
        while(t && t->val != value) {
            father = t;
            if(t->val < value) t = t->right;
            else t = t->left;
        }
        if(t == NULL) return root;
        TreeNode *r = NULL;
        if(t->right) {
            r = t->right;
            while(r->left) r = r->left;
        }
        if(r) {
            t->val = r->val;
            t->right = removeNode(t->right, r->val);
        }
        else {
            if(father->left == t) father->left = t->left;
            else father->right = t->left;
            delete t;
        }
        return HEAD.left;
    }
};