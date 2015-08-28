class Solution {
    /** 
     * param A : an integer sorted array
     * param target :  an integer to be inserted
     * return : an integer
     */
public:
    int searchInsert(vector<int> &A, int target) {
        // write your code here
        int l = 0, r = A.size();
        while(l < r) {
            int m = l +(r-l)/2;
            if(A[m] < target) l = m+1;
            else r = m;
        }
        return l;
    }
};
