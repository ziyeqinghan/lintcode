class Solution {
public:
    /**
     * @param nums: A list of integers
     * @return: An integer indicate the value of maximum difference between two
     *          Subarrays
     */
    int maxDiffSubArrays(vector<int> nums) {
        // write your code here
        int n = nums.size();
        if(n == 0) return 0;
        int maxleft[n], minleft[n], maxl = nums[0], minl = nums[0];
        maxleft[0] = nums[0], minleft[0] = nums[0];
        for(int i = 1; i < n; i++) {
            maxl = max(maxl, 0)+nums[i];
            minl = min(minl, 0)+nums[i];
            maxleft[i] = max(maxleft[i-1], maxl);
            minleft[i] = min(minleft[i-1], minl);
        }
        int ans = 0, maxright = nums[n-1], minright = nums[n-1], maxr = 0, minr = 0;
        for(int i = n-1; i > 0; i--) {
            maxr = max(maxr, 0)+nums[i];
            minr = min(minr, 0)+nums[i];
            maxright = max(maxright, maxr);
            minright = min(minright, minr);
            ans = max({ans, abs(maxright-minleft[i-1]), abs(minright-minleft[i-1]), abs(maxright-maxleft[i-1]), abs(minright-maxleft[i-1])});
        }
        return ans;
    }
};

