class Solution {
public:
    /**
     * @param nums: A list of integers
     * @return: An integer denotes the sum of max two non-overlapping subarrays
     */
    int maxTwoSubArrays(vector<int> nums) {
        // write your code here
        int n = nums.size();
        if(n == 0) return 0;
        int maxleft[n], maxl = nums[0];
        maxleft[0] = nums[0];
        for(int i = 1; i < n; i++) {
            maxl = max(maxl, 0)+nums[i];
            maxleft[i] = max(maxleft[i-1], maxl);
        }
        int ans = INT_MIN, maxright = nums[n-1], maxr = 0;
        for(int i = n-1; i > 0; i--) {
            maxr = max(maxr, 0)+nums[i];
            maxright = max(maxright, maxr);
            ans = max(ans, maxright+maxleft[i-1]);
        }
        return ans;
    }
};

