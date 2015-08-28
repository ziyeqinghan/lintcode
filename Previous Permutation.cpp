class Solution {
public:
    /**
     * @param nums: An array of integers
     * @return: An array of integers that's previous permuation
     */
    vector<int> previousPermuation(vector<int> &nums) {
        // write your code here
        int n = nums.size(), i = 0;
        for(i = n-1; i >= 1;i--) {
            if(nums[i-1] > nums[i]) {
                for(int j = n-1; j >= i; j--) {
                    if(nums[j] < nums[i-1]) {
                        swap(nums[i-1], nums[j]);
                        break;
                    }
                }
                break;
            }
        }
        reverse(nums.begin()+i, nums.end());
        return nums;
    }
};
