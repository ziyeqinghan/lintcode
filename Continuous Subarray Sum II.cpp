class Solution {
public:
    /**
     * @param A an integer array
     * @return  A list of integers includes the index of 
     *          the first number and the index of the last number
     */
    vector<int> continuousSubarraySumII(vector<int>& A) {
        // Write your code here
        int n = A.size();
        if(n == 0) return {};
        int l = 0, sum = A[0], maxs = A[0], al = 0, ar = 0;
        int l2 = 0, sum2 = A[0], mins = A[0], ml = 0, mr = 0, totsum = A[0];
        for(int i = 1; i < n; i++) {
            totsum += A[i];
            if(sum < 0) l = i;
            sum = max(sum, 0)+A[i];
            if(maxs < sum) {
                al = l; ar = i;
                maxs = sum;
            }
            if(sum2 > 0) l2 = i;
            sum2 = min(sum2, 0)+A[i];
            if(mins > sum2) {
                ml = l2; mr = i;
                mins = sum2;
            }            
        }
        if(mr-ml < n-1 && totsum-mins > maxs) return {mr+1, ml-1};
        return {al, ar};
    }
};
