class Solution {
public:
    /**
     * @param T1, T2: The roots of binary tree.
     * @return: True if T2 is a subtree of T1, or false.
     */
    bool isIdentical(TreeNode *T1, TreeNode *T2) {
        if(T1 == NULL && T2 == NULL) return true;
        else if(T1 == NULL || T2 == NULL) return false;
        if(T1->val != T2->val) return false;
        return isIdentical(T1->left, T2->left) && isIdentical(T1->right, T2->right);
    }
    bool isSubtree(TreeNode *T1, TreeNode *T2) {
        // write your code here
        if(T2 == NULL) return true;
        else if(T1 == NULL) return false;
        if(isIdentical(T1, T2)) return true;
        return isSubtree(T1->left, T2) || isSubtree(T1->right, T2);
    }
};