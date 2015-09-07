class Solution {
public:
    /**
     * @param nums: a vector of integers
     * @return: nothing
     */
    void partitionArray(vector<int> &nums) {
        // write your code here
        int j = 0;
        for(int i = 0; i < nums.size(); i++) 
            if((nums[i]&1) == 1) swap(nums[j++], nums[i]);
    }
};
