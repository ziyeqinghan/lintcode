class Solution {
public:
    /**
     *@param A: a list of integer
     *@return: The root of Segment Tree
     */
    SegmentTreeNode * __build(vector<int>& A, int l, int r) {
        SegmentTreeNode* t = new SegmentTreeNode(l, r, 0);
        if(l == r) 
            t->max = A[l];
        else {
            int m = (l+r)/2;
            t->left = __build(A, l, m);
            t->right = __build(A, m+1, r);
            t->max = max(t->left->max, t->right->max);
        }
    }
    SegmentTreeNode * build(vector<int>& A) {
        // write your code here
        int n = A.size();
        if(n == 0) return NULL;
        return __build(A, 0, n-1);
    }
};
