class Solution {
public:
    /**
     *@param start, end: Denote an segment / interval
     *@return: The root of Segment Tree
     */
    SegmentTreeNode * build(int start, int end) {
        // write your code here
        if(start > end) return NULL;
        SegmentTreeNode* t = new SegmentTreeNode(start, end);
        if(start == end) return t;
        t->left = build(start, start+(end-start)/2);
        t->right = build(start+(end-start)/2+1, end);
        return t;
    }
};
