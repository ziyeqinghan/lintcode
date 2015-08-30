class Solution {
public:
    /**
     *@param root, start, end: The root of segment tree and 
     *                         an segment / interval
     *@return: The maximum number in the interval [start, end]
     */
    int query(SegmentTreeNode *root, int start, int end) {
        // write your code here
        if(root->start >= start && root->end <= end) return root->max;
        if(end <= root->left->end) return query(root->left, start, end);
        if(start >= root->right->start) return query(root->right, start, end);
        return max(query(root->left, start, end), query(root->right, start, end));
    }
};