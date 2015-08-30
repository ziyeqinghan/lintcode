class Solution {
public:
    /**
     *@param root, index, value: The root of segment tree and 
     *@ change the node's value with [index, index] to the new given value
     *@return: void
     */
    void modify(SegmentTreeNode *root, int index, int value) {
        // write your code here
        if(root == NULL) return;
        if(root->start == index && index == root->end) root->max = value;
        else if(root->start <= index && index <= root->end) {
            modify(root->left, index, value);
            modify(root->right, index, value);
            root->max = max(root->left->max, root->right->max);
        }
    }
};