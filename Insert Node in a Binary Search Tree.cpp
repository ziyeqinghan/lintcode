class Solution {
public:
    /**
     * @param root: The root of the binary search tree.
     * @param node: insert this node into the binary search tree
     * @return: The root of the new binary search tree.
     */
    TreeNode* insertNode(TreeNode* root, TreeNode* node) {
        // write your code here
        if(root == NULL) return node;
        TreeNode * father = root, *t = root;
        while(t) {
            father = t;
            if(t->val < node->val) t = t->right;
            else if(t->val > node->val) t = t->left;
            else return root;
        }
        if(father->val < node->val) father->right = node;
        else father->left = node;
        return root;
    }
};
