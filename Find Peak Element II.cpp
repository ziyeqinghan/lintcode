class Solution {
public:
    /**
     * @param A: An integer matrix
     * @return: The index of the peak
     */

    vector<int> findPeakII(vector<vector<int> > A) {
        // write your code here
        int m = A.size(), n = A[0].size();
        int l = 1, r = m-2;
        while(l <= r) {
            int mid = l+(r-l)/2;
            int y = distance(A[mid].begin(), max_element(A[mid].begin(), A[mid].end()));
            if(A[mid][y] < A[mid+1][y]) l = mid+1;
            else if(A[mid][y] < A[mid-1][y]) r = mid-1;
            else return {mid, y};
        }
        return {};
    }
};

