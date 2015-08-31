class Solution {
public:
    /**
     *@param root, start, end: The root of segment tree and 
     *                         an segment / interval
     *@return: The count number in the interval [start, end] 
     */
    int query(SegmentTreeNode *root, int start, int end) {
        // write your code here
        if(root == NULL) return 0;
        if(start <= root->start && root->end <= end) return root->count;
        if(start > root->end || end < root->start) return 0;
        return query(root->left, start, end)+query(root->right, start, end);
    }
};