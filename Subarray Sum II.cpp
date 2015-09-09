class Solution {
public:
    /**
     * @param A an integer array
     * @param start an integer
     * @param end an integer
     * @return the number of possible answer
     */
    int subarraySumII(vector<int>& A, int start, int end) {
        // Write your code here
        int n = A.size();
        if(n == 0) return 0;
        int i = 0, j = 1, k = 1;
        int sumi = 0, sumj = A[0], sumk = A[0];
        int ans = 0;
        while(i < n) {
            if(j <= n && sumj-sumi < start) {
                if(j < n)
                    sumj += A[j];
                j++;
            }
            else if(k <= n && sumk-sumi <= end) {
                if(k < n)
                    sumk += A[k];
                k++;
            }
            else {
                ans += k-j;
                sumi += A[i++];
                if(i == j) sumj += A[j++];
                if(i == k) sumk += A[k++];
            }
        }
        return ans;
    }
};
