class Solution {
public:
    /**
     * @param A an integer array
     * @return  A list of integers includes the index of 
     *          the first number and the index of the last number
     */
    vector<int> continuousSubarraySum(vector<int>& A) {
        // Write your code here
        int n = A.size();
        if(n == 0) return {};
        int l = 0, sum = A[0], maxs = A[0], al = 0, ar = 0;
        for(int i = 1; i < n; i++) {
            if(sum < 0) l = i;
            sum = max(sum, 0)+A[i];
            if(maxs < sum) {
                al = l; ar = i;
                maxs = sum;
            }
        }
        return {al, ar};
    }
};
