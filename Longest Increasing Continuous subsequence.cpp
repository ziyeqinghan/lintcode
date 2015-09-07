class Solution {
public:
    /**
     * @param A an array of Integer
     * @return  an integer
     */
    int longestIncreasingContinuousSubsequence(vector<int>& A) {
        // Write your code here
        int n = A.size();
        int i = 0, ans = 0;
        while(i < n) {
            int p = i;
            while(p+1 < n && A[p] < A[p+1]) p++;
            int v = p;
            while(v+1 < n && A[v] > A[v+1]) v++;
            ans = max({p-i+1, v-p+1, ans});
            if(i == v) i++;
            else i = v;
        }
        return ans;
    }
};
