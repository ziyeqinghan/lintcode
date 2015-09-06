class Solution {
public:
    /**
     * @param A, B: Two integer arrays.
     * @return: Their smallest difference.
     */
    int smallestDifference(vector<int> &A, vector<int> &B) {
        // write your code here
        sort(A.begin(), A.end());
        sort(B.begin(), B.end());
        int ans = INT_MAX;
        int i = 0, j = 0;
        while(i < A.size() && j < B.size()) {
            if(A[i] < B[j]) ans = min(ans, B[j]-A[i++]);
            else ans = min(ans, A[i]-B[j++]);
        }
        return ans;
    }
};

