class Solution {
public:
    /**
     * @param nums: A list of integers
     * @param k: An integer denote to find k non-overlapping subarrays
     * @return: An integer denote the sum of max k non-overlapping subarrays
     */
    int maxSubArray(vector<int> nums, int k) {
        // write your code here
        int n = nums.size();
        vector<vector<int>> f(n+1, vector<int>(k+1, 0));
        for(int i = 1; i <= n; i++) {
            for(int j = 1; j <= min(k, i); j++) {
                f[i][j] = f[i-1][j-1]+nums[i-1];
                int maxs = nums[i-1], sum = nums[i-1];
                for(int k = i-2; k >= max(0, j-1); k--) {
                    sum = max(sum, 0)+nums[k];
                    maxs = max(maxs, sum);
                    f[i][j] = max(f[i][j], f[k][j-1]+maxs);
                }
            }
        }
        return f[n][k];
    }
};

