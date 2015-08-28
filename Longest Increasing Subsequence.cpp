class Solution {
public:
    /**
     * @param nums: The integer array
     * @return: The length of LIS (longest increasing subsequence)
     */
    int longestIncreasingSubsequence(vector<int> nums) {
        // write your code here
        int n = nums.size();
        if(n == 0) return 0;
        int f[n];
        memset(f, 0, sizeof(f));
        for(int i = 0; i < n; i++) {
            f[i] = 1;
            for(int j = 0; j < i; j++)
                if(nums[j] <= nums[i]) f[i] = max(f[i], f[j]+1);
        }
        return *max_element(f, f+n);
    }
};

