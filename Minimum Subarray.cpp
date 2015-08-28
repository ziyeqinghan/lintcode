class Solution {
public:
    /**
     * @param nums: a list of integers
     * @return: A integer denote the sum of minimum subarray
     */
    int minSubArray(vector<int> nums) {
        // write your code here
        int n = nums.size();
        if(n == 0) return 0;
        int ans = nums[0], sum = nums[0];
        for(int i = 1; i < n; i++) {
            sum = min(sum, 0)+nums[i];
            ans = min(ans, sum);
        }
        return ans;
    }
};

